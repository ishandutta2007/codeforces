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
#define N 500009
using namespace std;

int n,cnt,a[N],a0[N],c[N];
multiset<int> S; multiset<int>:: iterator it;
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
void add(int x,int y){
	for (; x<=n; x+=x&-x) c[x]+=y;
}
int qry(int x){
	int y=0; for (; x; x^=x&-x) y+=c[x]; return y;
}
void ins(int x,int y){
	//cerr<<"ins: "<<x<<" "<<y<<'\n';
	if (x>y) return;
	add(x,1); add(y+1,-1);	
}
int solve(){
	int i,j;
	cnt=0;
	for (i=1; i<=n; i++) if (a[i]) a[++cnt]=a[i];
	n=cnt;
	if (!n) return 0;
	sort(a+1,a+n+1);
	S.clear();
	for (i=j=1; i<=a[n]; i++){
	//	cerr<<i<<"?"<<'\n';
		for (; a[j]<i; j++); S.insert(j);
	}
	//for (auto p:S) printf("%d ",p);puts("");
	memset(c,0,sizeof(c));
	int ans=0;
	for (i=n; i; i--){
		//cerr<<'\n'<<i<<'\n';
		int t=a[i]-qry(i);
		//cerr<<a[i]<<' '<<qry(i)<<' '<<t<<' ';
		S.erase(i);
		int now=i;
		//cerr<<S.size()<<'\n';
		if (S.size()) now=*S.begin();
		if (t>i-now){
			ans+=t-(i-now);
			t=i-now;
		}
		//cerr<<t<<'\n';
		if (!t) continue; int t0=t; 
		t=i-t;
		it=S.upper_bound(t); it--;
		//cerr<<":*it"<<(*it)<<'\n';
		if ((*it)==t){
			S.erase(it); ins(t,i-1);	
		} else{
			int l=*it; S.erase(it);
			it=S.upper_bound(t);
			int r;
			if (it==S.end()){
				r=i;
			} else{
				r=*it;
				S.erase(it);
			}
			S.insert(l+(t0-(i-1-r+1)));
			ins(r,i-1); ins(l,l+(t0-(i-1-r+1))-1);
		}
	}
	//cerr<<"ans:"<<ans<<'\n';
	return ans;
}
int main(){
	scanf("%d",&n);
	int i,x;
	for (i=1; i<=n; i++){
		scanf("%d",&x);
		if (x) a[++cnt]=x;
	}
	if (!cnt){
		puts("0"); return 0;
	}
	n=cnt;
	int n0=n; memcpy(a0,a,sizeof(a));
	int l=solve();
	n=n0;
	for (i=1; i<=n; i++) a[i]=a0[i]-1;
	int r=n0-solve();
	if (l>r) puts("-1"); else{
	//	printf("%d\n",(r-l)/2+1);
		for (; l<=r; l+=2) printf("%d%c",l,l<r?' ':'\n');
	}
	return 0;
}