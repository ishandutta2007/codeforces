#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42,mod=998244353;

int n,k;

int dp[nmax];

int dp_2[2][nmax][nmax];

vector<int> cur={};

vector< vector<int> > active;

bool test()
{
    int LHS=0,total=0;

    for(int id=cur.size()-1;id>=0;id--)
    {
        for(int i=1;i<=cur[id];i++)
        {
            total++;

            LHS=LHS+total*(id+1);

            if(LHS>n)return 0;
        }
    }

    //cout<<"testing ";for(auto w:cur)cout<<w<<" ";cout<<" -> "<<LHS<<" "<<total<<endl;

    return 1;
}

void dfs(int sum_remain,int prv)
{
    if(cur.size())
    {
        if(test()==0)return;

        active.push_back(cur);
    }
    for(int take=1;take<=prv&&take<=sum_remain;take++)
    {
        cur.push_back(take);

        dfs(sum_remain-take,take);

        cur.pop_back();
    }

}
int solve()
{
    dp[0]=1;

    if(k==1)
    {
        for(int num=1;num<=n;num++)
            for(int j=n;j>=0;j--)
                for(int cnt=1;cnt*num<=j;cnt++)
                    dp[j]=(dp[j]+dp[j-num*cnt])%mod;

        /*
        for(int i=1;i<=n;i++)
            cout<<i<<" -> "<<dp[i]<<endl;
        */

        int outp=0;
        for(int i=1;i<=n;i++)
            outp=(outp+dp[i])%mod;

        return outp;
    }

    if(k==2)
    {
        dp_2[1][0][n]=1;

        int outp=0;
        for(int i=1;(i-1)*i/2<=n;i++)
        {
            for(int sum=0;sum<=n;sum++)
                for(int prv=1;(i-1)*prv<=sum&&prv<=n;prv++)
                    if(dp_2[i&1][sum][prv])
                {
                    if(sum)outp=(outp+dp_2[i&1][sum][prv])%mod;

                    for(int cur=1;cur<=prv&&sum+cur*i<=n;cur++)
                    {
                        dp_2[!(i&1)][sum+cur*i][cur]=(dp_2[!(i&1)][sum+cur*i][cur]+dp_2[i&1][sum][prv])%mod;
                    }

                    //if(dp_2[i&1][sum][prv])cout<<i<<" "<<sum<<" "<<prv<<" -> "<<dp_2[i&1][sum][prv]<<endl;

                    dp_2[(i&1)][sum][prv]=0;
                }
        }

        return outp;
    }

    dfs(n,n);

    k=k-3;

    /*
    for(auto k:active)
    {
        for(auto w:k)cout<<w<<" ";
        cout<<endl;
    }
    */

    for(int t=1;t<=k;t++)
    {
        set< vector<int> > help={};

        for(auto &w:active)
        {
            sort(w.begin(),w.end());

            vector<int> ret={};

            int cnt=1;

            for(int j=1;j<w.size();j++)
                if(w[j-1]==w[j])cnt++;
                else
                {
                    ret.push_back(cnt);
                    cnt=1;
                }
            ret.push_back(cnt);
            sort(ret.begin(),ret.end());

            help.insert(ret);
        }

        active={};
        for(auto k:help)
            active.push_back(k);
    }
    /*
    cout<<"to"<<endl;
    for(auto k:active)
    {
        for(auto w:k)cout<<w<<" ";
        cout<<endl;
    }
    */
    return active.size();
}

int main()
{
    scanf("%i%i",&n,&k);

    printf("%i\n",solve());
    return 0;
}