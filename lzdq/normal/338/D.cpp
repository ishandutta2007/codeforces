#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1e4+5;
ll n,m,a[MAXN],p,q;
int k;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b) return x=1,y=0,a;
	ll res=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return res;
}
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
ll mul(ll a,ll b,ll m){
	ll res=0;
	while(b){
		if(b&1) res=(res+a)%m;
		b>>=1;
		a=a*2%m;
	}
	return res;
}
void Add(ll a,ll b){
	a=(a+b)%b;
	ll x,y;
	ll d=exgcd(b,q,x,y);
	if(n/q<b/d||q/b*d>n||(a-p)%d) puts("NO"),exit(0);
	y=(y%(b/d)+b/d)%(b/d);
	x=((a-p)/d%(b/d)*y%(b/d)+b/d)%(b/d);
	x=(mul((a-p)/d,y,b/d)+b/d)%(b/d);
	p+=x*q;
	q*=b/d;
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%lld%lld%d",&n,&m,&k);
	a[0]=1;
	q=1;
	for(int i=1; i<=k; i++){
		scanf("%lld",a+i);
		Add(1-i,a[i]);
	}
	//printf("%lld %lld\n",p,q);
	if(!p) p=q;
	if(p>m-k+1) return puts("NO"),0;
	for(int i=1; i<=k; i++)
		if(gcd(q,p+i-1)!=a[i]) return puts("NO"),0;
	puts("YES");
	return 0;
}