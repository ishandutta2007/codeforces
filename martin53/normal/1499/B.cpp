#include<bits/stdc++.h>
using namespace std;

const int nmax=100+5;

int dp[nmax][nmax];

string inp;

bool can(int pos,int prv)
{
    if(pos==inp.size())return 1;

    if(dp[pos][prv]!=-1)return dp[pos][prv];

    int ret=0;

    if(inp[prv]<=inp[pos]&&can(pos+1,pos))ret=1;

    if(pos-1==prv&&can(pos+1,prv))ret=1;

    //cout<<pos<<" "<<prv<<" -> "<<ret<<endl;

    dp[pos][prv]=ret;

    return ret;
}
void solve()
{
    cin>>inp;

    inp="00"+inp;

    memset(dp,-1,sizeof(dp));

    if(can(2,1))printf("YES\n");
    else printf("NO\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}