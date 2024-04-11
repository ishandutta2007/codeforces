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

const int maxn = 1e3 + 5;
const int maxm = 1e3 + 5;

int n, m, k;
char ans[maxn][maxm];
char s[maxn * maxm];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s);
	sort(s, s + n * m);
	//puts(s);
	int st = 0, ed = n * m - 1, hd = 0, tl = k - 1;
	FOR(i, 0, m){
		//printf("i = %d hd = %d tl = %d\n", i, hd, tl);
		REP(j, hd, tl) ans[j][i] = s[st++];
		for(int j = hd - 1; j >= 0; --j) ans[j][i] = s[ed--];
		for(int j = n - 1; j > tl; --j) ans[j][i] = s[ed--];
		REP(j, hd, tl) if(ans[j][i] == ans[tl][i]){
			hd = j;
			break;
		}
	}
	FOR(i, 0, n) puts(ans[i]);
	return 0;
}

/*
3 3 3
abcabcabc

4 3 4
aeeaeebcbbcc

3 3 3
aaabbcdde
*/