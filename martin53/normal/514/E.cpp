#include<bits/stdc++.h>
using namespace std;
const int lim=102,mod=1e9+7;
long long original[lim][lim],ans[lim][lim],help[lim][lim];
void make()
{
for(int i=1;i<lim-1;i++)
    original[i-1][i]=1;
original[lim-1][lim-1]=1;
}
void mult_original()
{
    memset(help,0,sizeof(help));
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)
            help[i][j]=(help[i][j]+original[i][k]*original[k][j])%mod;
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            original[i][j]=help[i][j];
}
void mult_ans()
{
    memset(help,0,sizeof(help));
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            for(int k=0;k<lim;k++)
            help[i][j]=(help[i][j]+ans[i][k]*original[k][j])%mod;
    for(int i=0;i<lim;i++)
        for(int j=0;j<lim;j++)
            ans[i][j]=help[i][j];
}
int main()
{
int n,x,d;
make();
cin>>n>>x;
for(int i=1;i<=n;i++)
{
    cin>>d;
    original[d][lim-1]++;
    original[d][1]++;
}

for(int i=0;i<lim;i++)
    ans[i][i]=1;

x++;
while(x)
{
    if(x%2==1)
        mult_ans();
    mult_original();
    x=x/2;
}
cout<<(ans[0][lim-1]+1)%mod<<endl;
return 0;
}