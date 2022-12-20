#include<bits/stdc++.h>
using namespace std;

const int nmax=16;

int n,inp[nmax];

int dp[1<<nmax][nmax][nmax];//dp[mask][i][pos] -> mask' : least sum[mask'] if there are i operations and the last merge is on pos

int sum[1<<nmax],bits[1<<nmax];

pair< pair<int/*mask*/,int/*wrong*/>,int/*position*/> parent[1<<nmax][nmax][nmax];

vector<int> on[1<<nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&inp[i]);

    for(int i=0;i<(1<<n);i++)
    {
        sum[i]=0;
        bits[i]=0;

        for(int j=n-1;j>=0;j--)
        {
            if((i&(1<<j)))sum[i]+=inp[j],bits[i]++;

            for(int t=0;t<n;t++)
                dp[i][j][t]=1<<n;
        }
    }

    sum[1<<n]=1e9;

    dp[(1<<n)-1][0][0]=0;

    for(int mask=(1<<n)-1;mask>=0;mask--)
        for(int wrong=0;wrong<n;wrong++)
            for(int pos=0;pos<n;pos++)
                if(dp[mask][wrong][pos]!=(1<<n))
                {
                //cout<<mask<<" "<<wrong<<" "<<pos<<" -> "<<dp[mask][wrong][pos]<<endl;

                int prv_mask=dp[mask][wrong][pos];

                for(int cur_mask=mask;cur_mask;cur_mask=(cur_mask-1)&mask)
                    if(sum[prv_mask]<sum[cur_mask])
                        //for(int where_to_merge=pos;where_to_merge<n;where_to_merge++)
                        for(auto where_to_merge:on[cur_mask])
                            if(where_to_merge<pos)break;
                            else
                            if(sum[cur_mask]<sum[dp[mask-cur_mask][wrong+bits[cur_mask]-1][where_to_merge]])
                            {
                            dp[mask-cur_mask][wrong+bits[cur_mask]-1][where_to_merge]=cur_mask;
                            parent[mask-cur_mask][wrong+bits[cur_mask]-1][where_to_merge]={{mask,wrong},pos};
                            }
                }

    int outp=n,mem_pos=0,mem_wrong=0,mem_mask=0;

    for(int wrong=0;wrong<n;wrong++)
        for(int pos=0;pos<n;pos++)
            if(dp[0][wrong][pos]!=(1<<n))
            {
                outp=wrong;
                mem_pos=pos;
                mem_wrong=wrong;

                pos=n;
                wrong=n;
            }
    printf("%i\n",outp);

    vector< pair<int,int> > to_print={};

    while(mem_mask!=(1<<n)-1)
    {
        int prv_mask=parent[mem_mask][mem_wrong][mem_pos].first.first;
        int prv_wrong=parent[mem_mask][mem_wrong][mem_pos].first.second;
        int prv_pos=parent[mem_mask][mem_wrong][mem_pos].second;

        int diff=mem_mask^prv_mask;

        for(int i=0;i<n;i++)
            if(i!=mem_pos&&((1<<i)&diff))to_print.push_back({i+1,mem_pos+1});

        mem_pos=prv_pos;
        mem_mask=prv_mask;
        mem_wrong=prv_wrong;
    }

    /*
    cout<<"original"<<endl;
    for(int i=0;i<outp;i++)
        printf("%i %i\n",to_print[i].first,to_print[i].second);
    cout<<"---"<<endl;
    */

    for(int i=0;i<outp;i++)
    {
        printf("%i %i\n",to_print[i].first,to_print[i].second);

        for(auto &k:to_print)
        {
            if(to_print[i].first<k.first)k.first--;
            if(to_print[i].first<k.second)k.second--;
        }
    }
}

int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<(1<<15);i++)
    {
        for(int j=15;j>=0;j--)
            if((i&(1<<j)))on[i].push_back(j);
    }
    while(t)
    {
        t--;
        solve();
    }

    return 0;
}