#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ui unsigned int
#define pb push_back
#define llu long long unsigned
using namespace std;
const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){if(p==q){p=ib,q=ib+fread(ib,1,MB,stdin);if(p==q)return 0;}return *p++;}
	template<typename T>
	void read_int(T& x){char c=read_char(),l=0;for(x=0;!isdigit(c);c=read_char())l=c;for(;isdigit(c);c=read_char())x=x*10-'0'+c;if(l=='-')x=-x;}
	void write_char(char c){if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);*r++=c;}
	template<typename T>
	void write_int(T x){if(x<0)write_char('-'),x=-x;do stk[++tp]=x%10+'0';while(x/=10);while(tp)write_char(stk[tp--]);}
}IO;
//IO.read_int(a);c=IO.read_char();IO.write_int(a);//IO.write_char(c);
const int N=500010;
int T,n,a[N],kk;
ll sum[N];
ll wz[N],val[N],f[N];
bool cmp(ll x,ll y){
	return x<y;
}
ll c[N],d[N];
int lowbit(int x){
	return x&(-x);
}
void update1(int x,ll y){
	d[x]=max(d[x],y);
}
ll query1(int x){
	return d[x];
}
void update2(int x,ll y){
	for(int i=x;i<=kk;i+=lowbit(i)){
		c[i]=max(c[i],y);
	}
}
ll query2(int x){
	ll res=-1e18;
	for(int i=x;i>=1;i-=lowbit(i)){
		res=max(res,c[i]);
	}
	return res;
}
int main(){
	scanf("%d",&T);
//	T=1;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			wz[i]=sum[i];
		}
		wz[n+1]=sum[n+1]=0;
		sort(wz+1,wz+n+2,cmp);
		kk=unique(wz+1,wz+n+2)-wz-1;
		for(int i=0;i<=n;i++){
			val[i]=lower_bound(wz+1,wz+kk+1,sum[i])-wz;
		}
		for(int i=0;i<=kk;i++){
			d[i]=c[i]=-1e18;
		}
		update1(val[0],0);
		update2(val[0],0);
		for(int i=1;i<=n;i++){
			ll maxn=max(query1(val[i]),query2(val[i]-1)+i);
			f[i]=max(maxn,f[i-1]-1);
			update1(val[i],f[i]);
			update2(val[i],f[i]-i);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}