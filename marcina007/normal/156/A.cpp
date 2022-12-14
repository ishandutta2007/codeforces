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

string s,u;
int res;

int main(){ 
	//in
	cin >> s >> u;
	//sol
	s = string(u.size(), '!') + s + string(u.size(), '!');
	res = u.size();
	for(int i=0;i+u.size() <= s.size(); i++){
		int act = 0;
		REP(j,u.size())
			act += (s[i+j] != u[j]);
		res = min(res, act);
	}
	//out
	cout << res << endl;
    return 0;
}