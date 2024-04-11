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
#include <queue>
#include <sstream>
#include <utility>
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

struct State {
	int goats[2], wolves[2];
	int side;
};

bool operator < (State a, State b) {
	REP (i, 2)
		if (a.goats[i] != b.goats[i])
			return a.goats[i] < b.goats[i];
		else if (a.wolves[i] != b.wolves[i])
			return a.wolves[i] < b.wolves[i];
	return a.side < b.side;
}

bool operator == (State a, State b) {
	return !(a < b) && !(b < a);
}

int m, n;

int hash(State s) {
	int res = 0;
	if (s.goats[0] == 0)
		res += 0;
	else if (s.goats[1] == 0)
		res += 1;
	else
		res += 2;
	res *= 3;
	if (s.wolves[1] == 0)
		res += 0;
	else if (s.wolves[0] == 0)
		res += 1;
	else
		res += 2;
	REP (i, 2)
		if (s.goats[i] != 0 && s.goats[i] != m) {
			res += 9 * s.goats[i];
			break;
		} else if (s.wolves[i] != 0 && s.wolves[i] != m) {
			res += 9 * s.wolves[i];
			break;
		}
	return 2 * res + s.side;
}

bool got[4000005];

queue<pair<State, int> > q;

void go(State s, int cd) {
	for (int g = 0; g <= s.goats[s.side] && g <= n; ++g) {
		for (int w = 0; w <= s.wolves[s.side] && (g == 0 || w <= g) && w + g <= n; ++w) {
			if (g + w == 0)
				continue;
			State s2 = s;
			s2.goats[s.side] -= g;
			s2.wolves[s.side] -= w;
			if (s2.goats[s.side] > 0 && s2.goats[s.side] < s2.wolves[s.side])
				continue;
			s2.goats[!s.side] += g;
			s2.wolves[!s.side] += w;
			if (s2.goats[!s.side] > 0 && s2.goats[!s.side] < s2.wolves[!s.side])
				continue;
			s2.side = !s.side;
			if (!got[hash(s2)]) {
				got[hash(s2)] = true;
				q.push(MP(s2, cd + 1));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &m, &n);

	if (m * LL(n) * LL(n) <= 100000000) {

		State final;
		final.goats[0] = final.wolves[0] = 0;
		final.goats[1] = final.wolves[1] = m;
		final.side = 1;

		State start;
		start.goats[0] = start.wolves[0] = m;
		start.goats[1] = start.wolves[1] = 0;
		start.side = 0;

		q.push(MP(start, 0));

		got[hash(start)] = true;

		while (!q.empty()) {
			State c = q.front().ST;
			int cd = q.front().ND;
			q.pop();
			if (c == final) {
				printf("%d\n", cd);
				return 0;
			}
			go(c, cd);
		}
		printf("-1\n");
	} else {
		if (n == m + 1) {
			printf("3\n");
			return 0;
		}
		n /= 2;
		m -= min(m, n);
		--n;
		printf("%d\n", 1 + 2 * ((m + n - 1) / n));
	}


	return 0;
}