#include<bits/stdc++.h>
using namespace std;
const int nmax=1.5e5+42;
string inp;

string one="one";
string two="two";
int dp[nmax][3][3];

int SZ;
int rec(int pos,int fi,int se)
{
    if(fi==3||se==3)return 1e9;
    if(pos==SZ)return 0;
    if(dp[pos][fi][se]!=-1)return dp[pos][fi][se];
    int ret=rec(pos+1,fi,se)+1;//take
    //ignore
    int fi_=fi,se_=se;
    if(inp[pos]==one[fi_])fi_++;
    else if(inp[pos]==one[0])fi_=1;
    else fi_=0;

    if(inp[pos]==two[se_])se_++;
    else if(inp[pos]==two[0])se_=1;
    else se_=0;

    ret=min(ret,rec(pos+1,fi_,se_));
    dp[pos][fi][se]=ret;
    return ret;
}

vector<int> ret={};
void print(int pos,int fi,int se)
{
    if(pos==SZ)return;
    //take
    if(rec(pos,fi,se)==1+rec(pos+1,fi,se))
    {
        ret.push_back(pos);
        print(pos+1,fi,se);
        return;
    }
    //ignore
    int fi_=fi,se_=se;
    if(inp[pos]==one[fi_])fi_++;
    else if(inp[pos]==one[0])fi_=1;
    else fi_=0;

    if(inp[pos]==two[se_])se_++;
    else if(inp[pos]==two[0])se_=1;
    else se_=0;

    print(pos+1,fi_,se_);
}
vector<int> solve()
{
    cin>>inp;
    SZ=inp.size();
    for(int i=0;i<SZ;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            dp[i][j][k]=-1;

    ret={};
    rec(0,0,0);

    print(0,0,0);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        vector<int> output=solve();
        cout<<output.size()<<endl;
        for(auto k:output)cout<<k+1<<" ";cout<<endl;
    }

    return 0;
}