//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT


int st[10005];
int ss;

int main()
{
	string s;
	while (!cin.eof()) {
		string buf;
		cin >> buf;
		s += buf;
	}

	s += "      ";

	int n = SIZE(s);

	vector<int> v;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '<' && s.substr(i, 3) == "<ta") {
			st[ss++] = 0;
			continue;
		} else if (s[i] == '<' && s.substr(i, 4) == "</ta") {
			v.PB(st[--ss]);
		} else if (s[i] == '<' && s.substr(i, 3) == "<td")
			++st[ss - 1];
	}

	sort(ALL(v));

	FORE (it, v)
		printf("%d ", *it);
	printf("\n");

    return 0;
}