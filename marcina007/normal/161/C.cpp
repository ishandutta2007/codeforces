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

int res = 0;
set<VI> M;

void go(int l1, int r1, int l2, int r2){
	if(r1<l1 || r2<l2) return;
	VI v;
	v.PB(l1);
	v.PB(r1);
	v.PB(l2);
	v.PB(r2);
	if(M.count(v)) return;
	M.insert(v);
	if(min(r1-l1+1, r2-l2+1) <= res) return;
		int n = 30;
		while((1<<n) > max(r1,r2)) n--;
		int p = 1<<n;
		if(l1 <= p && p <= r1 && l2 <= p && p <= r2)
			res = max(p-max(l1,l2) + min(r1,r2)-p + 1, res);
		if(l1>p){go(l1-p,r1-p,l2,r2); return;}
		if(l2>p){go(l1,r1,l2-p,r2-p); return;}
		if(l1 <= p && p <= r1){
			go(l1,p-1,l2,r2);
			go(1,r1-p,l2,r2);
			return;
		}
		if(l2 <= p && p <= r2){
			go(l1,r1,l2,p-1);
			go(l1,r1,1,r2-p);
			return;
		}
}

int main(){ 
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	go(a,b,c,d);
	cout << res << endl;
    return 0;
}