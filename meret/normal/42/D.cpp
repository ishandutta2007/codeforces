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

int v[21];

bool got[2001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		v[i] = v[i - 1] + 1;
		while (true) {
			bool ok = true;
			for (int j = 1; j < i; ++j)
				if (got[v[j] + v[i]]) {
					ok = false;
					break;
				}
			if (!ok)
				++v[i];
			else
				break;
		}
		for (int j = 1; j < i; ++j)
			got[v[j] + v[i]] = true;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				printf("0");
			else if (i < j)
				printf("%d", v[i] + v[j]);
			else
				printf("%d", v[i] + v[j]);
			if (j < n)
				printf(" ");
		}
		printf("\n");
	}

    return 0;
}