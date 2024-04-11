#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define fst first
#define snd second
#define MP make_pair
#define PB push_back
#define PH push
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

int n, m, ans = 105;
int a[105][105];

int main(){
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) FOR(j, 0, n) scanf("%d", &a[i][j]);
	FOR(i, 0, n - 1){
		int sum = 0;
		vector<pii> vec;
		FOR(j, 0, m) sum += a[j][i] - a[j][n - 1], vec.PB(MP(a[j][i] - a[j][n - 1], j));
		sort(vec.begin(), vec.end());
		int res = 0;
		FOR(j, 0, vec.size()){
			if(sum >= 0) break;
			++res;
			sum -= vec[j].fst;
		}
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	FOR(i, 0, n - 1){
		int sum = 0;
		vector<pii> vec;
		FOR(j, 0, m) sum += a[j][i] - a[j][n - 1], vec.PB(MP(a[j][i] - a[j][n - 1], j));
		sort(vec.begin(), vec.end());
		int res = 0;
		FOR(j, 0, vec.size()){
			if(sum >= 0) break;
			++res;
			sum -= vec[j].fst;
		}
		if(res == ans){
			//printf("i = %d\n", i);
			FOR(j, 0, res) printf("%d ", vec[j].snd + 1);
			//puts("");
			return 0;
		}
	}
	return 0;
}