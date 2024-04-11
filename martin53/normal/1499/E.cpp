#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,mod=998244353;

int dp[nmax][nmax][27];

string x,y;

int rec(int pos_x,int pos_y,int which_prv)
{
    if(pos_x==x.size()&&pos_y==y.size())return 1;

    if(dp[pos_x][pos_y][which_prv]!=-1)return dp[pos_x][pos_y][which_prv];

    int ret=1;//stop

    if(pos_x<x.size()&&which_prv!=x[pos_x]-'a')ret=(ret+rec(pos_x+1,pos_y,x[pos_x]-'a'))%mod;
    if(pos_y<y.size()&&which_prv!=y[pos_y]-'a')ret=(ret+rec(pos_x,pos_y+1,y[pos_y]-'a'))%mod;

    dp[pos_x][pos_y][which_prv]=ret;
    return ret;
}

int where_wrong[2][nmax];

void prec(string s,int id)
{
    for(int l=0;l<s.size();l++)
    {
        int r=l+1;

        while(r<s.size()&&s[r-1]!=s[r])r++;

        where_wrong[id][l]=r;
    }
}
int main()
{
    cin>>x>>y;

    /*
    for(int i=0;i<1000;i++)x.push_back('a'+i%26);
    y=x;
    */

    prec(x,0);
    prec(y,1);

    memset(dp,-1,sizeof(dp));

    int ret=0;

    for(int i=0;i<x.size();i++)
        for(int j=0;j<y.size();j++)
        {
            ret=(ret+rec(i,j,26))%mod;

            int sub_x=where_wrong[0][i]-i;
            int sub_y=where_wrong[1][j]-j;

            //cout<<i<<" "<<j<<" "<<sub_x<<" "<<sub_y<<endl;

            ret=(ret-sub_x-sub_y-1+mod)%mod;
        }
    cout<<ret<<endl;

    return 0;
}