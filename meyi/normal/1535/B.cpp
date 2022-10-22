#include<bits/stdc++.h>
using namespace std;
inline int gcd(int x,int y)
{
	if(!x)
		return y;
	if(!y)
		return x;
	if(x==y)
		return x;
	if(x>y)
		return gcd(x-y,x);
	return (x,y-x);
}
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
inline bool cmp(int x,int y){
	if((x&1)==(y&1))return x>y;
	return x*((x&1)?1:-1)<y*((y&1)?1:-1);
}
ll a[maxn];
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	clock_t st=clock();
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%lld",a+i);
		sort(a+1,a+n+1,cmp);
		ri ans=0;
		for(ri i=1;i<n;++i)
			for(ri j=i+1;j<=n;++j)
				if(gcd(a[i],2*a[j])>1)
					++ans;
		if(!t_case)while(clock()-st<=1900);
		printf("%d\n",ans);
	}
	return 0;
}