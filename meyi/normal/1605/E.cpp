#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
vector<int>pri;
bool vis[maxn];
int mu[maxn];
inline void sieve(int siz){
	mu[1]=1;
	for(ri i=2;i<=siz;++i){
		if(!vis[i])mu[i]=-1,pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0){
				mu[i*j]=0;
				break;
			}
			mu[i*j]=-mu[i];
		}
	}
}
int a1,a[maxn],b1,b[maxn],len[3],m,n;
ll ans[maxn],calc1,pre[3][maxn],v[3][maxn];
inline ll calc0(ll k){
	ri pos=lower_bound(v[0]+1,v[0]+len[0]+1,-k)-v[0];
	return (pre[0][len[0]]-pre[0][pos-1]+(len[0]-pos+1)*k)-(pre[0][pos-1]+(pos-1)*k);
}
inline ll calc2(ll k){
	ri pos=lower_bound(v[2]+1,v[2]+len[2]+1,-k)-v[2];
	return (pre[2][len[2]]-pre[2][pos-1]+(len[2]-pos+1)*k)-(pre[2][pos-1]+(pos-1)*k);
}
int main(){
	scanf("%d%d",&n,&a1);
	sieve(n);
	for(ri i=2;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&b1);
	for(ri i=2;i<=n;++i){
		scanf("%d",b+i),a[i]-=b[i];
		for(ri j=i;j<=n;j+=i)ans[j]+=mu[j/i]*a[i];
		v[mu[i]+1][++len[mu[i]+1]]=ans[i];
	}
	sort(v[0]+1,v[0]+len[0]+1);
	for(ri i=1;i<=len[0];++i)pre[0][i]=pre[0][i-1]+v[0][i];
	for(ri i=1;i<=len[1];++i)calc1+=abs(v[1][i]);
	sort(v[2]+1,v[2]+len[2]+1);
	for(ri i=1;i<=len[2];++i)pre[2][i]=pre[2][i-1]+v[2][i];
	scanf("%d",&m);
	while(m--){
		scanf("%d",&b1);
		a[1]=a1-b1;
		printf("%lld\n",abs(mu[1]*a[1])+calc0(-a[1])+calc1+calc2(a[1]));
	}
	return 0;
}