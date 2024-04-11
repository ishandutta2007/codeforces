#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;
int n,a[9],b[N],ans;
pii c[N];

int cc[N],tot;
void add(int x) {
	if((cc[c[x].se]++)==0) tot++;
}
void del(int x) {
	if((--cc[c[x].se])==0) tot--;
}

signed main() {
	rep(i,1,6) a[i]=read();
	n=read();
	rep(i,1,n) b[i]=read();
	int cnt=0;
	rep(i,1,n) rep(j,1,6) c[++cnt]=pii(-a[j]+b[i],i);
	sort(c+1,c+cnt+1);
	ans=c[cnt].fi-c[1].fi; int r=0;
	rep(l,1,cnt-n+1) {
		if(l) del(l-1);
		while(r+1<=cnt&&tot<n) add(++r);
		if(tot<n) break;
		ans=min(ans,c[r].fi-c[l].fi);
	}
	printf("%lld\n",ans);
	return 0;
}