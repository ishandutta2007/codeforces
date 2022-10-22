#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int fac[maxn];
vector<int>pri;
inline void sieve(int siz){
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!fac[i])fac[i]=i,pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			fac[i*j]=j;
			if(i%j==0)break;
		}
	}
}
ll ans=1;
int m,n;
map<int,int>cnt1[maxn],cnt2[maxn];
inline void insert(int pos,int x){
	while(x>1){
		ri tmp=fac[x];
		if(++cnt1[tmp][++cnt2[pos][tmp]]==n)ans=ans*tmp%mod;;
		x/=tmp;
	}
}
int main(){
	sieve(200000);
	scanf("%d%d",&n,&m);
	for(ri i=1,a;i<=n;++i){
		scanf("%d",&a);
		insert(i,a);
	}
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}