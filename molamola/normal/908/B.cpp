#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

char S[55][55];

void solve() {
	int p[4] = {};
	int n, m; scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", S[i]);
	char A[110]; scanf("%s", A);
	rep(i, 4) p[i] = i;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int ans = 0;
	do{
		int sx = -1, sy = -1;
		rep(i, n) rep(j, m) if(S[i][j] == 'S') sx = i, sy = j;
		int des = 0;
		for(int i=0;A[i];i++) {
			int q = p[A[i] - '0'];
			sx += dx[q], sy += dy[q];
			if(0 <= sx && sx < n && 0 <= sy && sy < m) {
				if(S[sx][sy] == '#') break;
				if(S[sx][sy] == 'E') { des = 1; break; }
			}
			else break;
		}
		ans += des;
	}while(next_permutation(p, p+4));
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}