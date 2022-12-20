#include<bits/stdc++.h>
using namespace std;

const int nmax=1e4+42;

string inp,aim;

int dp[nmax][nmax];

int skip[nmax];

int rec(int pos_inp,int pos_aim)
{
    if(pos_inp==inp.size())
    {
        if(pos_aim==aim.size())return 0;
        return 1e9;
    }

    if(dp[pos_inp][pos_aim]!=-1)return dp[pos_inp][pos_aim];

    //cout<<pos_inp<<" "<<pos_aim<<endl;

    int ret=rec(pos_inp+1,pos_aim)+1;

    if(pos_aim<aim.size()&&inp[pos_inp]==aim[pos_aim])ret=min(ret,rec(pos_inp+1,pos_aim+1));

    if(pos_aim>=1&&inp[pos_inp]=='.')ret=min(ret,rec(pos_inp+1,pos_aim-1));

    if(skip[pos_inp]!=-1)ret=min(ret,rec(skip[pos_inp],pos_aim));

    dp[pos_inp][pos_aim]=ret;

    return ret;
}
int main()
{
    cin>>inp>>aim;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<inp.size();i++)
    {
        skip[i]=-1;
        if(inp[i]=='.')continue;

        int sum=0;
        for(int j=i;j<inp.size();j++)
        {
            if(inp[j]=='.')sum--;
            else sum++;

            if(sum==0)
            {
                skip[i]=j+1;
                break;
            }
        }
    }

    cout<<rec(0,0)<<endl;

    return 0;
}