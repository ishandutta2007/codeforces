#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, p[MX], q[MX], pPos[MX];
int SEG[MX*4], LAZY[MX*4];

void addSeg(int i, int j, int x, int lazy=0, int p=0, int l=0, int r=n-1) {
	SEG[p] += lazy;
	LAZY[p] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEG[p] += x;
		LAZY[p] += x;
		return;
	}
	int m=(l+r)/2;
	addSeg(i,j,x,LAZY[p],p*2+1,l,m);
	addSeg(i,j,x,LAZY[p],p*2+2,m+1,r);
	SEG[p] = max(SEG[p*2+1], SEG[p*2+2]);
	LAZY[p] = 0;
}

void program() {
	cin>>n;
	RE(i,n) cin>>p[i];
	RE(i,n) pPos[p[i]]=i;
	RE(i,n) cin>>q[i];
	RE(i,n*4) SEG[i]=LAZY[i]=0;
	int x=n+1;
	RE(i,n) {
		while(SEG[0]<=0) {
			x--;
			addSeg(0,pPos[x],1);
		}
		cout<<(i==0?"":" ")<<x;
		addSeg(0,q[i]-1,-1);
	}
	cout<<endl;
}