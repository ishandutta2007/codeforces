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

#define LIM 100007
map<VI, lli> M;
bool zl[LIM];
int pot10[5]={1,10,100,1000,10000};

lli go(VI v){
	if(!M.count(v)){
		int n = v.size();

		if(n == 1){
			int res = 0;
			REP(i,10) {
				if(!zl[10*v[0]+i])
					res++;
			}
			M[v]=res;
			return res;
		}

		VI vv=v;
		int a = v.back();
		vv.pop_back();

		REP(i,pot10[n]) {
			int x = a*pot10[n]+i;
			if(!zl[x]){
	//			cout << "pos " << x << endl;
				VI w(vv);
				REP(i,n-1){
					w[i] = w[i]*10 + (x%10);
					x /= 10;
				}
	//			cout << w.size() << " " << w[0] << " " << go(w) << endl;
				M[v] += go(w);
			}
		}

	}
	return M[v];
}

lli sol(lli x){
	VI v;
	while(x){
		v.PB(x%10);
		x /= 10;
	}
	v.pop_back();
	return go(v);
}

int main(){ 
	//zl
	zl[0]=zl[1]=true;
	FOR(i,2,LIM-1)
		if(!zl[i]){
			for(lli j=2*i;j<LIM;j+=i)
				zl[j]=true;
		}
	//
//	FOR(i,1,9999)
//		cout << sol(i) << endl;
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		cout << sol(x) << endl;
	}
    return 0;
}