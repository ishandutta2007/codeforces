#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e7+10,mx=20000000;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
		}
	}
}
int cnt[maxn],n;
ll f[maxn];
int main(){
	sieve(mx);
	scanf("%d",&n);
	for(ri i=1,x;i<=n;++i){
		scanf("%d",&x);
		++cnt[x];
	}
	for(ri i:pri)
		for(ri j=mx/i;j;--j)
			cnt[j]+=cnt[j*i];
	for(ri i=mx;i;--i)
		if(cnt[i]){
			f[i]=1ll*cnt[i]*i;
			for(ri j:pri){
				if(i*j>mx)break;
				ckmax(f[i],f[i*j]+1ll*(cnt[i]-cnt[i*j])*i);
			}
		}
	printf("%lld",f[1]);
	return 0;
}