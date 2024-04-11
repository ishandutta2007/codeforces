#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct node{
	ll a,b;
	char c;
};
vector<node>v;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
inline void insert(ll x,ll y){
	vector<ll>tmp;
	while(y){
		if(y&1)tmp.push_back(x);
		v.push_back({x,x,'+'});
		x+=x;
		y>>=1;
	}
	for(ri i=1;i<tmp.size();++i){
		v.push_back({tmp[0],tmp[i],'+'});
		tmp[0]+=tmp[i];
	}
}
ll m,n,x,y;
signed main(){
	scanf("%lld",&n);
	ll m=n<<(63-__builtin_clzll(n));
	for(ll i=n;i<m;i<<=1)v.push_back({i,i,'+'});
	ll k=n^m;
	v.push_back({n,m,'^'});
	if(k&1){
		v.push_back({k,k,'+'});
		k<<=1;
	}
	exgcd(n,k,y,x);
	if(x>=0)x-=n;
	x=-x;
	y=(k*x+1)/n;
	insert(k,x);
	insert(n,y);
	v.push_back({n*y,k*x,'^'});
	printf("%d\n",(int)v.size());
	for(node i:v)printf("%lld %c %lld\n",i.a,i.c,i.b);
	return 0;
}