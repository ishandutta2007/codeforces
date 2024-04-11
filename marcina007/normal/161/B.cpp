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
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 1007
int n,k,c[MAXN],t[MAXN],poz=1;
vector<P> sto, pen;
vector<int> res[MAXN];
bool dis[MAXN];
lli price;

int main(){ 
	//in
	scanf("%d%d",&n,&k);
	FOR(i,1,n) {
		scanf("%d%d",&c[i],&t[i]);
		price += 2 * c[i];
	}
	//sol
	FOR(i,1,n)
		(t[i] == 1 ? sto : pen).PB(P(c[i], i));
	sort(ALL(sto)); reverse(ALL(sto));
	sort(ALL(pen)); reverse(ALL(pen));
	//
	FORE(i,sto) {
		res[poz].PB(i->Y);
		dis[poz] = true;
		poz=min(poz+1, k);
	}
	FORE(i,pen) {
		res[poz].PB(i->Y);
		poz=min(poz+1, k);
	}
	//
	FOR(p,1,k) if(dis[p]) {
		int mi = ((1E9)+7);
		FORE(i,res[p]) mi = min(mi, c[*i]);
		price -= mi;
	}
	//out
	cout << price/2;
	if(price%2) cout << ".5";
	else cout << ".0";
    cout << endl;	
	FOR(i,1,k){
		printf("%d ", res[i].size());
		FORE(j,res[i]) printf("%d ", *j);
		printf("\n");
	}
    return 0;
}