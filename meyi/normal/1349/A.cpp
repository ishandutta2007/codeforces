#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
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
int a[maxn],n;
ll ans=1;
vector<int>v[maxn];
int main(){
	sieve(200000);
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		while(a[i]>1){
			ri j=fac[a[i]],k=0;
			do a[i]/=j,++k;while(a[i]%j==0);
			v[j].push_back(k);
		}
	}
	for(ri i=2;i<200001;++i)
		if(v[i].size()>=n-1){
			sort(v[i].begin(),v[i].end());
			for(ri j=1;j<=v[i][v[i].size()==n-1?0:1];++j)ans*=i;
		}
	printf("%lld",ans);
	return 0;
}