#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
string word;
string small[3];

int nx[26][nmax];

int dp[255][255][255];

int best(int a,int b,int c)
{
    int ret=nmax;
    if(a!=-1)ret=min(ret,a);
    if(b!=-1)ret=min(ret,b);
    if(c!=-1)ret=min(ret,c);
    if(ret==nmax)return -1;
    return ret;
}
int main()
{
memset(nx,-1,sizeof(nx));
memset(dp,-1,sizeof(dp));
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

int n,q;
cin>>n>>q>>word;

word=" "+word;

small[0]=" ";
small[1]=" ";
small[2]=" ";

for(int j=0;j<26;j++)
    nx[j][n+1]=-1;

for(int i=n;i>=1;i--)
{
    for(int j=0;j<26;j++)
        nx[j][i]=nx[j][i+1];
    nx[word[i]-'a'][i]=i;

}

dp[0][0][0]=0;
char type;
int id;
char a;
for(int Q=1;Q<=q;Q++)
{
    cin>>type>>id;
    id--;
    if(type=='-')
    {
        small[id].pop_back();
        int SZ=small[id].size();

        if(id==0)
        {
            for(int j=0;j<=small[1].size();j++)
                for(int k=0;k<=small[2].size();k++)
                dp[SZ][j][k]=-1;
        }

        if(id==1)
        {
            for(int i=0;i<=small[0].size();i++)
                for(int k=0;k<=small[2].size();k++)
                dp[i][SZ][k]=-1;
        }


        if(id==2)
        {
            for(int i=0;i<=small[0].size();i++)
                for(int j=0;j<=small[1].size();j++)
                dp[i][j][SZ]=-1;
        }

        dp[0][0][0]=0;
    }
    else
    {
        cin>>a;

        int SZ=small[id].size();

        small[id].push_back(a);

        if(id==0)
        {
            for(int j=0;j<small[1].size();j++)
                for(int k=0;k<small[2].size();k++)
                {
                int p=nx[a-'a'][dp[SZ-1][j][k]+1];
                int q=(j==0?-1:nx[small[1][j]-'a'][dp[SZ][j-1][k]+1]);
                int r=(k==0?-1:nx[small[2][k]-'a'][dp[SZ][j][k-1]+1]);
                dp[SZ][j][k]=best(p,q,r);
                }
        }


        if(id==1)
        {
            for(int i=0;i<small[0].size();i++)
                for(int k=0;k<small[2].size();k++)
                {
                int p=nx[a-'a'][dp[i][SZ-1][k]+1];
                int q=(i==0?-1:nx[small[0][i]-'a'][dp[i-1][SZ][k]+1]);
                int r=(k==0?-1:nx[small[2][k]-'a'][dp[i][SZ][k-1]+1]);
                dp[i][SZ][k]=best(p,q,r);
                }
        }

        if(id==2)
        {
            for(int i=0;i<small[0].size();i++)
                for(int j=0;j<small[1].size();j++)
                {
                int p=nx[a-'a'][dp[i][j][SZ-1]+1];
                int q=(i==0?-1:nx[small[0][i]-'a'][dp[i-1][j][SZ]+1]);
                int r=(j==0?-1:nx[small[1][j]-'a'][dp[i][j-1][SZ]+1]);
                dp[i][j][SZ]=best(p,q,r);
                }
        }

    }
    /*    for(int i=0;i<small[0].size();i++)
        for(int j=0;j<small[1].size();j++)
            for(int k=0;k<small[2].size();k++)
                cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    */
    if(dp[small[0].size()-1][small[1].size()-1][small[2].size()-1]!=-1)cout<<"YES\n";
    else cout<<"NO\n";
}
return 0;
}