#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAXN=100010;
typedef long long LL;
const LL INF=1000000000000000000LL;
int n,c[MAXN];
LL f[MAXN][2];
string str[MAXN],rev[MAXN];
string reverse(string str)
{
    string res="";
    for(int i=0;i<str.size();i++)
        res=str[i]+res;
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>str[i],rev[i]=reverse(str[i]);
    for(int i=1;i<=n;i++) f[i][0]=f[i][1]=INF;
    f[1][0]=0,f[1][1]=c[1];
    for(int i=2;i<=n;i++)
    {
        if(str[i]>=str[i-1]) f[i][0]=min(f[i][0],f[i-1][0]);
        if(str[i]>=rev[i-1]) f[i][0]=min(f[i][0],f[i-1][1]);
        if(rev[i]>=str[i-1]) f[i][1]=min(f[i][1],f[i-1][0]+c[i]);
        if(rev[i]>=rev[i-1]) f[i][1]=min(f[i][1],f[i-1][1]+c[i]);
    }
    //for(int i=1;i<=n;i++) cout<<str[i]<<" "<<rev[i]<<endl;
    LL ans=min(f[n][0],f[n][1]);
    if(ans==INF) puts("-1");
    else cout<<ans<<endl;
    return 0;
}