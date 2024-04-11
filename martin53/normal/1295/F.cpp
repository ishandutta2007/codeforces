#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,nmax=200+42;

long long my_pow(long long a,int b)
{
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}
long long inv(long long a)
{
    //cout<<"inv "<<a<<" -> "<<my_pow(a,mod-2)<<endl;

    return my_pow(a,mod-2);
}
int n;

pair<int,int> inp[nmax];

long long dp[nmax][nmax];//dp[pos][group] -> probability to have x<=group[i].second as position pos

vector< pair<int,int> > groups;

void gen()
{
    set<int> active={0};
    for(int i=1;i<=n;i++)
    {
        active.insert(inp[i].first);
        active.insert(inp[i].second);
    }

    vector<int> given={};
    for(auto k:active)
        given.push_back(k);

    groups.push_back({-1,-1});
    groups.push_back({0,0});

    for(int i=1;i<given.size();i++)
    {
        if(given[i-1]+1<=given[i]-1)groups.push_back({given[i-1]+1,given[i]-1});
        groups.push_back({given[i],given[i]});
    }
}

long long pick(long long SZ,int nums)//1<=v[1]<=v[2]<=...v[nums]<=SZ
{
    long long ret=1;

    for(int i=1;i<=nums;i++)
        ret=ret*(SZ-1+i)%mod*inv(i)%mod;

    //cout<<"pick "<<SZ<<" "<<nums<<" -> "<<ret<<endl;

    return ret;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    reverse(inp+1,inp+n+1);

    gen();

    /*
    cout<<"groups: "<<endl;
    for(auto k:groups)
        cout<<k.first<<" "<<k.second<<endl;
    cout<<"---"<<endl;
    */

    for(int i=0;i<groups.size();i++)
        dp[0][i]=1;

    for(int pos=1;pos<=n;pos++)
    {
        for(int group=0;group<groups.size();group++)
        {
            for(int le=pos;le>=1;le--)
            {
                long long RHS=1;
                for(int p=le;p<=pos&&RHS;p++)
                    if(max(inp[p].first,groups[group].first)>min(inp[p].second,groups[group].second))RHS=0;
                    else RHS=RHS*(inp[p].second-inp[p].first+1)%mod;

                if(RHS==0)break;
                long long LHS=pick(groups[group].second-groups[group].first+1,pos-le+1);

                long long prob=LHS*inv(RHS)%mod;
                prob=prob*dp[le-1][group-1]%mod;

                //cout<<le<<" -> "<<prob<<" LHS= "<<LHS<<" RHS= "<<RHS<<endl;

                dp[pos][group]=(dp[pos][group]+prob)%mod;
            }

            if(group)
            {
                dp[pos][group]=(dp[pos][group]+dp[pos][group-1])%mod;

                /*
                cout<<pos<<" "<<group<<" -> "<<dp[pos][group]<<endl;

                cout<<"---"<<endl;
                */
            }
        }
    }

    for(int i=groups.size()-1;i>=0;i--)
        if(inp[n].second==groups[i].second)
        {
            printf("%lld\n",dp[n][i]);
            return 0;
        }

    assert(0==1);

    return 0;
}