#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,mod=998244353;
int n,m,T,mn;
int f[maxn],g[maxn],h[maxn];
inline int inc(int x){
	return x>=mod? x-mod:x;
}
int main(){
	scanf("%d%d",&n,&m);
	f[0]=1,mn=0;
	for(int v=m;v<=n;v++){
		if(mn+v>n)
			break;
		for(int i=v;i<=n;i++)
			g[i]=inc(g[i-v]+f[i-v]);
		mn=n+1;
		for(int i=0;i<=n;i++){
			f[i]=g[i],h[i]=inc(h[i]+g[i]),g[i]=0;
			if(f[i])
				mn=min(mn,i);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",h[i],i==n? '\n':' ');
	return 0;
}