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
#include <cassert>
#include <utility>
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


int t[4];

void inc(int x) {
	printf("+%d\n", x + 1);
	++t[x];
	++t[(x + 1) % 4];
}

void halve(int x) {
	printf("/%d\n", x + 1);
	t[x] /= 2;
	t[(x + 1) % 4] /= 2;
}

int main()
{
	for (int i = 0; i < 4; ++i)
		scanf("%d", &t[i]);

	while (true) {
		bool got = false;
		int i = rand() % 4;
		for (int z = 0; z < 4; ++z) {
			i = (i + 1) % 4;
			int j = (i + 1) % 4;
			if (rand() % 4 == 0) {
				inc(i);
				got = true;
				continue;
			}
			if (t[i] != 1 || t[j] != 1) {
				got = true;
				if (t[i] % 2 == 1 && t[j] % 2 == 1)
					inc(i);
				else if (t[i] % 2)
					inc((i + 3) % 4);
				else if (t[j] % 2)
					inc(j);
				halve(i);
			}
		}
		if (!got)
			break;
	}

    return 0;
}