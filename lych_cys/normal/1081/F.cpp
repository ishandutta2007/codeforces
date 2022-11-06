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

int n,m,cnt,last,now,a[309]; pii e[1000009]; vector<pii > p;
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
int ask(int l,int r){
	printf("? %d %d\n",l,r); fflush(stdout);
	return read();	
}
void ins(int l,int r){ e[++cnt]=mpr(l,r); }
void gao(int l,int r){
	for (; l<=r; l++) if (a[l]!=-1) a[l]^=1;
}
void work(){
	int t=rand()%5+1;
	while (t--){
		int k=(rand()+rand())%p.size();
		int x=p[k].fi,y=p[k].se;
		last=now; now=ask(x,y);
		if ((now^last^y)&1){
			ins(x,n); gao(x,n);
		} else{
			ins(1,y); gao(1,y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	if (n==1){
		printf("! %d\n",m); fflush(stdout); return 0;
	}
	now=m;
	for (i=1; i<=n; i++)
		for (j=i; j<=n; j++) if (j-i+1+n&1) p.pb(mpr(i,j));
	for (i=1; i<=n; i++) a[i]=-1;
	for (i=1; i<n; i++){
		while (a[i]==-1){
			work();
			int x=rand()%n+1;
			if (x>i){
				int l=i+1,r=x;
				if ((n^r^l)&1) continue;
				last=now; now=ask(l,r);
				if ((now^last^r)&1){
					ins(l,n); gao(l,n);
					a[i]=now-last+n-i>>1; a[i]=now-a[i];
					for (j=1; j<i; j++) a[i]-=a[j]; break;
				} else{
					ins(1,r); gao(1,r);
				}
			} else{
				int l=x,r=i;
				if ((n^r^l)&1) continue;
				last=now; now=ask(l,r);
				if ((now^last^r)&1){
					ins(l,n); gao(l,n);
				} else{
					ins(1,r); gao(1,r);
					a[i]=now-last+r>>1;
					for (j=1; j<i; j++) a[i]-=a[j]; break;
				}
			}
		}
	}
	a[n]=now;
	for (i=1; i<n; i++) a[n]-=a[i];
	for (i=cnt; i; i--) gao(e[i].fi,e[i].se);
	putchar('!'); putchar(' ');
	for (i=1; i<=n; i++) printf("%d",a[i]); puts(""); fflush(stdout);
	return 0;
}