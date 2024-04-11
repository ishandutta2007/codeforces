#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
#define pb emplace_back
typedef vector<int> vi;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
#define MT make_tuple
typedef tuple<int, int, int> iii;

#define INF 1000000005
#define MAXN 200005

int t;
int n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("9");
		int cur = 8;
		REP (i, 1, n) {
			printf("%d", cur);
			cur++;
			cur %= 10;
		}
		printf("\n");
	}
	return 0;
}