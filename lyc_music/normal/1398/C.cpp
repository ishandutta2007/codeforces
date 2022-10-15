#include<bits/stdc++.h>
#define int long long
#define N 1000000
int n,T,ans,a[N],s[N],b[N];
char st[N];
using namespace std;
signed main()
{
cin>>T;
while (T--)
{
cin>>n;ans=0;
for (int i=1;i<=n;i++) cin>>st[i];
for (int i=1;i<=n;i++) a[i]=st[i]-'0',s[i]+=a[i]+s[i-1],b[s[i-1]-i+1]++,ans+=b[s[i]-i];
for (int i=n;i>=1;i--) b[s[i-1]-i+1]--,s[i]=0;
cout<<ans<<endl;
}
}