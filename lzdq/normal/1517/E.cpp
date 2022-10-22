#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pr;
#define mkp make_pair
const int MAXN=2e5+5,mod=998244353;
int n,m,a[MAXN];
ll s[MAXN],s2[MAXN];
pr b[MAXN*5];
inline bool cmp1(pr a,pr b){
	if(a.first==b.first) return (a.second&1)&&!(b.second&1);
	return a.first<b.first;
}
inline bool cmp2(pr a,pr b){
	if(a.first==b.first) return !(a.second&1)&&(b.second&1);
	return a.first<b.first;
}
int rsum[MAXN];
inline int Query(int x){
	int res=0;
	for(int i=x; i; i-=i&-i)
		res=(res+rsum[i])%mod;
	return res;
}
inline void Add(int x,int y){
	for(int i=x; i<=n; i+=i&-i)
		rsum[i]=(rsum[i]+y)%mod;
}
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=0;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		s2[1]=a[1];
		s[1]=a[1];
		for(int i=2; i<=n; i++){
			s[i]=s[i-1]+a[i];
			s2[i]=s2[i-2]+a[i];
		}
		// x&1,2|y
		m=0;
		for(int i=2; i<=n; i+=2){
			b[++m]=mkp(s2[i-1]-s2[i]+s[i],i);
			if(i<n) b[++m]=mkp(s2[i-1]-s2[i]+s[i]+a[n]*2,i);
		}
		b[++m]=mkp(s[n],1);
		for(int i=3; i<=n; i+=2){
			b[++m]=mkp(s2[i-2]-s2[i-1]-s[i-1]+s[n],i);
			b[++m]=mkp(s2[i-2]-s2[i-1]-s[i-1]+s[n]+2*a[1],i);
		}
		sort(b+1,b+m+1,cmp1);
		for(int i=1; i<=m; i++){
			if(b[i].second&1){
				ans=(ans+Query(n)-Query(b[i].second))%mod;
				/*
				printf("ans+=%d sec %d\n",Query(n)-Query(b[i].second),b[i].second);
				for(int j=1; j<i; j++)
					if(!(b[j].second&1)&&b[j].second>b[i].second){
						printf("%d %d\n",b[i].second,b[j].second);
					}
					*/
			}else Add(b[i].second,1);
		}
		for(int i=1; i<=n; i++)
			rsum[i]=0;
		// y&1,2|x
		m=0;
		for(int i=1; i<=n; i+=2){
			b[++m]=mkp(s2[i-1]-s2[i]+s[i],i);
			if(i<n) b[++m]=mkp(s2[i-1]-s2[i]+s[i]+a[n]*2,i);
		}
		for(int i=2; i<=n; i+=2){
			b[++m]=mkp(s2[i-2]-s2[i-1]-s[i-1]+s[n],i);
			b[++m]=mkp(s2[i-2]-s2[i-1]-s[i-1]+s[n]+2*a[1],i);
		}
		sort(b+1,b+m+1,cmp2);
		for(int i=1; i<=m; i++){
			if(!(b[i].second&1)){
				ans=(ans+Query(n)-Query(b[i].second))%mod;
				/*
				printf("ans+=%d sec %d\n",Query(n)-Query(b[i].second),b[i].second);
				for(int j=1; j<i; j++)
					if((b[j].second&1)&&b[j].second>b[i].second){
						printf("%d %d\n",b[i].second,b[j].second);
					}
					*/
			}else Add(b[i].second,1);
		}
		for(int i=1; i<=n; i++)
			rsum[i]=0;
		for(int i=0; i<=n; i++)
			if(s[n]-s[i]<s[i]) ans=(ans+1)%mod;
		printf("%d\n",ans);
	}
	return 0;
}