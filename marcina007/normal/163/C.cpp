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
#define TYP double
typedef pair<TYP, int> DP;

#define MAXN 100007
int n,l,v1,v2,a[MAXN];
vector<DP> events;
TYP res[MAXN];

int main(){ 
	//in
	scanf("%d%d%d%d",&n,&l,&v1,&v2);
	REP(i,n) scanf("%d",&a[i]);
	//sol
	TYP r=(((TYP)l)/(v1+v2))*v2;
	if(r >= 2*l) r = 2*l;
	int beg = 0;
	REP(i,n) if(a[i] <= r){
		beg++;
		events.PB(DP(2*l - r + ((TYP)a[i]), 1));
		events.PB(DP(((TYP)a[i]), -1));
	} else {
		events.PB(DP(((TYP)a[i]) - r, 1));
		events.PB(DP(((TYP)a[i]), -1));
	}
	sort(ALL(events));
	TYP last = 0.0;
	int act = beg;
	FORE(i,events){
		res[act] += i->X - last;
		act += i->Y;
		last = i->X;
	}
	res[act] += ((TYP)2*l)-last;
	//out
	TYP tog = 2 * l;
	REP(i,n+1){
		printf("%.13lf\n", res[i] / tog);
	//	cout << res[i] / tog << endl;
	}
    return 0;
}