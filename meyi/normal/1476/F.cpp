#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],c[maxn],f[maxn],n,pre[maxn];
char ans[maxn];
#define lowbit(k) (k&-k)
inline void add(int k,int v){
	k=n-k+1;
	for(;k<=n;k+=lowbit(k))ckmax(c[k],v);
}
inline int query(int k){
	k=n-k+1;
	ri ret=0;
	for(;k;k^=lowbit(k))ckmax(ret,c[k]);
	return ret;
}
int t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i){
			pre[i]=lower_bound(f,f+i,i-a[i]-1)-f;
			if(pre[i]<i){
				f[i]=max(i-1,query(pre[i]+1));
				if(f[i-1]>f[i])f[i]=f[i-1],pre[i]=i;
				if(f[i-1]>=i&&i+a[i]>f[i])f[i]=i+a[i],pre[i]=i;
			}
			else f[i]=f[i-1];
			add(i,i+a[i]);
		}
		if(f[n]<n)puts("NO");
		else{
			puts("YES");
			for(ri i=n;i;){
				if(pre[i]==i)ans[i--]='R';
				else ans[i]='L',fill(ans+pre[i]+1,ans+i,'R'),i=pre[i];
			}
			puts(ans+1);
		}
		for(ri i=1;i<=n;++i)ans[i]=c[i]=f[i]=pre[i]=0;
	}
	return 0;
}