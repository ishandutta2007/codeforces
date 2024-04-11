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
const int N=200010;
int T,n,a[N];
ll anss=1e18,num;
int ask(int x){
	if(x>1e9||x<1)exit(1);
	num++;
	if(num>n+30)exit(1);
	cout<<"? "<<x<<endl;
	ll ans;
	cin>>ans;
	if(ans==0)ans=1e9;
	anss=min(anss,ans*1ll*x);
	return ans;
}
void solve(int l,int r,int ansl,int ansr){
	if(ansr*1ll*l>=anss)return ;
	if(l+1>=r){
		return ;
	}
	int mid=(l+r)>>1;
	int kel=ask(mid);
	int okl=1,okr=1;
	if(kel==ansr){
		okr=0;
	}
	if(kel==ansl){
		okl=0;
	}
	if(okr){
		solve(mid,r,kel,ansr);
	}
	if(okl){
		solve(l,mid,ansl,kel);
	}
}
int main(){
//	scanf("%d",&T);
	T=1;
	while(T--){
		cin>>n;
		int r1=ask(1),r2=ask(n*2000+n-1);
		solve(1,n*2000+n-1,r1,r2);
//		printf("%lld\n",anss);
		cout<<"! "<<anss<<endl;
	}
	return 0;
}