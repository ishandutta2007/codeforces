#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007
int n,ans,a[N],s[N];vector<int> d[N];
int max(int x,int y) {return x>y?x:y;}
int qPow(int x,int y) {int res=1;for(;y;y>>=1,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res; } 
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),++s[a[i]],a[0]=max(a[0],a[i]);
	for(int i=1;i<=a[0];++i) s[i]+=s[i-1];for(int i=1;i<=a[0];++i) for(int j=i;j<=a[0];j+=i) d[j].push_back(i); 
	for(int i=1,sz,t;i<=a[0];++i)
	{
		sz=d[i].size();t=1;sort(d[i].begin(),d[i].end());
		for(int j=0;j<sz-1;++j) t=1ll*t*qPow(j+1,s[d[i][j+1]-1]-s[d[i][j]-1])%MOD;
		ans=(ans+1ll*t*(qPow(sz,s[a[0]]-s[d[i][sz-1]-1])-qPow(sz-1,s[a[0]]-s[d[i][sz-1]-1]))%MOD)%MOD;
	}printf("%d\n",(ans+MOD)%MOD);return 0;
}