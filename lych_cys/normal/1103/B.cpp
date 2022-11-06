#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool ask(int x,int y){
	//cerr<<x<<' '<<y<<'\n';
	//return x%1000000000>=y%1000000000;
	printf("? %d %d\n",x,y); fflush(stdout);
	char ch[10]; scanf("%s",ch);
	return ch[0]=='x';		
}
int main(){
	char ch[10];
	while (~scanf("%s",ch)){
		if (ch[0]=='e') break;
		if (ask(0,1)){ puts("! 1"); fflush(stdout); continue; }	
		ll i,j;
		for (i=1; ; i*=2){
			j=i*2;
			if (j>inf) j=inf;
			if (ask(i,j)) break;	
		}
	//	cerr<<"ij: "<<i<<' '<<j<<'\n';
		ll l=i+1,r=j,mid;
		while (l<r){
			mid=(ll)l+r>>1;
			if (ask(l-1,mid)) r=mid; else l=mid+1;	
		}
		printf("! %lld\n",l); fflush(stdout);
	}
	return 0;
}