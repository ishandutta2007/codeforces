#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,block=250,mod=998244353;

int n,k,inp[nmax];

int dp[nmax],val[nmax];

vector<int> seen[nmax];

vector< pair<int/*sum*/,int/*value*/> > there[nmax];

int which(int cur)
{
    return cur/block;
}

int sum_block[nmax];

void rebuild(int id)
{
    id=id/block;

    int LHS=max(1,id*block),RHS=id*block+block-1;

    there[id]={};

    int sum=0;
    for(int j=RHS;j>=LHS;j--)
    {
        sum+=val[j];

        there[id].push_back({sum,dp[j-1]});
    }

    sum_block[id]=sum;

    sort(there[id].begin(),there[id].end());

    for(int j=1;j<there[id].size();j++)
    {
        there[id][j].second=(there[id][j].second+there[id][j-1].second)%mod;
    }
    /*
    cout<<"build: "<<id<<endl;
    for(auto w:there[id])
        cout<<w.first<<" "<<w.second<<endl;
    cout<<"---"<<endl;
    */
}
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        int SZ=seen[inp[i]].size();

        if(SZ>=2)
        {
            val[seen[inp[i]][SZ-2]]=0;

            if(which(seen[inp[i]][SZ-2])!=which(i))rebuild(seen[inp[i]][SZ-2]);

            val[seen[inp[i]][SZ-1]]=-1;

            if(which(seen[inp[i]][SZ-1])!=which(i))rebuild(seen[inp[i]][SZ-1]);
        }
        if(SZ==1)
        {
            val[seen[inp[i]][SZ-1]]=-1;

            if(which(seen[inp[i]][SZ-1])!=which(i))rebuild(seen[inp[i]][SZ-1]);
        }

        val[i]=1;
        seen[inp[i]].push_back(i);

        //cout<<"val: ";for(int j=1;j<=i;j++)cout<<val[j]<<" ";cout<<endl;

        int LHS=max(1,i/block*block);

        int sum=0;
        for(int j=i;j>=LHS;j--)
        {
            sum+=val[j];

            if(sum<=k)dp[i]=(dp[i]+dp[j-1])%mod;
        }

        for(int cur=i/block-1;cur>=0;cur--)
        {
            int pos=lower_bound(there[cur].begin(),there[cur].end(),make_pair(k+1-sum,-1))-there[cur].begin();

            pos--;

            //cout<<"cur= "<<cur<<" pos= "<<pos<<endl;

            if(pos>=0)
            {
                dp[i]=(dp[i]+there[cur][pos].second)%mod;
            }
            /*
            for(auto w:there[cur])
                if(sum+w.first<=k)dp[i]=(dp[i]+w.second)%mod;
                else break;
            */

            sum=sum+sum_block[cur];
        }
        if(i/block!=(i+1)/block)rebuild(i);
        /*
        cout<<"dp "<<i<<" = "<<dp[i]<<endl;
        cout<<"---"<<endl;
        */
    }

    printf("%i\n",dp[n]);
    return 0;
}