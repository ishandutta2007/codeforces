#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
typedef long long ll;
using namespace std;
const int MAXN=1e6+5;
const ll INF=1ll<<60;
int n,a[MAXN];
ll m,b;
ll ans=INF;
set<int> prm;
void Div(int x){
	for(int i=2; i*i<=x; i++)
		if(x%i==0){
			prm.insert(i);
			while(x%i==0) x/=i;
		}
	if(x>1) prm.insert(x);
	return ;
}
int c[MAXN],s[MAXN];
ll Calc(int p){
	int l=0,r=0;
	ll res=INF;
	for(int i=1; i<=n; i++){
		if(a[i]%p==0) c[i]=0;
		else if(a[i]%p==1||a[i]%p==p-1) c[i]=1;
		else{
			if(!l) l=i;
			r=i;
			c[i]=0;
		}
		s[i]=s[i-1]+c[i];
	}
	if(l){
		ll m1=INF,m2=INF;
		for(int i=0; i<l; i++)
			m1=min(m1,b*s[i]+m*(l-i-1));
		for(int i=r; i<=n; i++)
			m2=min(m2,b*(s[n]-s[i])+m*(i-r));
		res=m1+m2+m*(r-l+1);
	}else{
		ll mx=-INF;
		for(int i=0; i<=n; i++){
			ll w=m*i-b*s[i];
			mx=max(mx,w);
			res=min(res,w-mx);
		}
		res+=b*s[n];
	}
	return res;
}
int main(){
	scanf("%d%lld%lld",&n,&m,&b);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	Div(a[1]-1);
	Div(a[1]);
	Div(a[1]+1);
	Div(a[n]-1);
	Div(a[n]);
	Div(a[n]+1);
	for(int p:prm) ans=min(ans,Calc(p));
	printf("%lld\n",ans);
	return 0;
}