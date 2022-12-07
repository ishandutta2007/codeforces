#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fi first
#define se second
#define eb emplace_back
#define bp __builtin_parity
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

int read() {
	int x=0,w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {x=x*10+c-'0'; c=getchar();}
	return x*w;
}

const int N=1029;

int n,q[N][N],dcs;

int qry(int l,int r,int k) {
	printf("? %d %d %d\n",l,r,k);
	fflush(stdout);
	int x=read();
	if(k==2) q[l][r]=x;
	return x;
}
void output(int x) {
	printf("! %d\n",x);
	fflush(stdout);
}

void solve() {
	int l=1,r=n;
	while(l+1<r) {
		int m=l+r>>1;
		int x=2*qry(1,m,2)-m, y=2*qry(m+1,n,2)-(n-m);
		if(x==y) {
			if(dcs) {
				if(dcs==1) r=m;
				else l=m+1;
			} else if(m>1) {
				int z=qry(1,m,n);
				if(z>1) l=m+1, dcs=2;
				else r=m, dcs=1;
			} else {
				int z=qry(m+1,n,n);
				if(z>1) r=m, dcs=1;
				else l=m+1, dcs=2;
			}
		} else if(x>y) r=m;
		else l=m+1;
	}
	if(l==r) {
		output(l);
	} else if(q[1][l-1]+1==q[1][r]) {
		int x=qry(1,l,2);
		if(q[1][l-1]+1==x) output(l);
		else output(r);
	} else if(q[r+1][n]+1==q[l][n]) {
		int x=qry(r,n,2);
		if(q[r+1][n]+1==x) output(r);
		else output(l);
	} else if(l>1) {
		int x=qry(1,l,n);
		if(x>1) output(r);
		else output(l);
	} else if(r<n) {
		int x=qry(r,n,n);
		if(x>1) output(l);
		else output(r);
	}
}

signed main() {
	n=read();
	q[1][n]=n/2+1;
	solve();
	return 0;
}