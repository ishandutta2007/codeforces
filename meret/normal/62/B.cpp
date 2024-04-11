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

set<int> pos[255];
set<int> pos2[255];

char s[300005];

int n, k;
//

int main()
{
	ios_base::sync_with_stdio(false);
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < k; ++i) {
		pos[s[i]].insert(i);
		pos2[s[i]].insert(-i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		LL res = 0;
		for (int j = 0; j < len; ++j) {
			int left = -1, right = -1;
			if (pos[s[j]].lower_bound(j) != pos[s[j]].end())
				right = *pos[s[j]].lower_bound(j);
			if (pos2[s[j]].lower_bound(-j) != pos2[s[j]].end())
				left = -*pos2[s[j]].lower_bound(-j);
			if (left == -1 && right == -1)
				res += len;
			else if (left != -1 && right != -1)
				res += min(j - left, right - j);
			else if (left != -1)
				res += j - left;
			else
				res += right - j;
		}
		cout << res << "\n";
	}

    return 0;
}