#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <complex>
#include <stack>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef long long unsigned llu;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<string> VS;
template<class C> inline void mini(C& a, C b) {a=min(a,b);}
template<class C> inline void maxi(C& a, C b) {a=max(a,b);}
#define INF ((lli)1E9)
#define MAXN 10007
int n,m,a,b,d[MAXN],l[MAXN],r[MAXN];
vector<P> kraw[MAXN], odw[MAXN];
VI post;
bool extra[MAXN], vis[MAXN], pocz[MAXN], kon[MAXN], ok[MAXN];

int main(){ 
	std::ios_base::sync_with_stdio(0);
	//in
	cin >> n >> m;
	FOR(i,1,m) {
		cin >> a >> b;
		kraw[a].PB(P(b,i));
		odw[b].PB(P(a,i));
	}
	//sol
	FORD(i,n,1) {
		kon[i] |= (i == n);
		FORE(j,kraw[i]) kon[i] |= kon[j->X];
	}
	//
	FOR(i,1,n) {
		pocz[i] |= (i == 1);
		FORE(j,kraw[i]) pocz[j->X] |= pocz[i];
	}
	FOR(i,1,n) ok[i] = (pocz[i] && kon[i]);
	//
	FOR(i,1,n) l[i]=-1, r[i]=2*MAXN;
	l[n]=r[n]=0;
	priority_queue<P> Q;
	FORD(q,n,1) if(ok[q]){
	r[q] = l[q];
	Q.push(P(0,q));
	while(!Q.empty()) {
		P p = Q.top(); Q.pop();
		int v = p.Y;
		if(r[v] - l[v] != -p.X) continue;
	//	cout << v << " " << l[v] << "-" << r[v] << endl;
		if(r[v] < l[v]){cout << "No" << endl; return 0;}
		FORE(i,kraw[v]) {
			int w = i->X;
			if(!ok[w]) continue;
			int d = r[w] - l[w];
			maxi(l[w], l[v]-2);
			mini(r[w], r[v]-1);
			if(r[w] - l[w] < d)
				Q.push(P(-(r[w]-l[w]), w));
		}
		FORE(i,odw[v]) {
			int w = i->X;
			if(!ok[w]) continue;
			int d = r[w] - l[w];
			maxi(l[w], l[v]+1);
			mini(r[w], r[v]+2);
			if(r[w] - l[w] < d)
				Q.push(P(-(r[w]-l[w]), w));
		}
	}
	}
	//out
	FOR(i,1,n) if(ok[i]) FORE(j,kraw[i]) if(ok[j->X])
		if(l[j->X] - l[i] == -2)
			extra[j->Y] = true;
	cout << "Yes" << endl;
	FOR(i,1,m)
		cout << 1+extra[i] << endl;
  return 0;
}