#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

using FL = long double;
int n, m;
char In[1010];
int score[1010];
FL fsc[20][150010];

FL f(int a, int x) { return fsc[a][x]; }

void read() {
	scanf("%s", In);
}

int output(int x) {
	printf("%d\n", x);
	fflush(stdout);
	int ans; scanf("%d", &ans);
	rep(i, n) {
		if(In[i] - '0' != ans) score[i] += 13;
		if(x != ans) score[i] -= 10;
	}
	return ans;
}

int main() {
	for(int i = 0; i < 150010; i++) {
		fsc[0][i] = 1;
		for(int a=1;a<20;a++) fsc[a][i] = (1.0 / i) * fsc[a-1][i];
	}
	scanf("%d%d", &n, &m);
	rep(i, n) score[i] = 1000;
	int a = 6;
	mt19937 rng(12345);
	rep(i, m) {
		read();
		FL sum[2] = {};
		rep(j, n) {
			sum[In[j] - '0'] += f(a, score[j]);
		}
		FL pick = uniform_real_distribution<FL>(0, sum[0] + sum[1])(rng);
		int res = 0;
		if(pick > sum[0]) res = 1;
		int rv = output(res);
		if(uniform_int_distribution<int>(0, 19)(rng) == 0) {
			if(a <= 3 || a >= 15) continue;
			FL nsum[3][2] = {};
			for(int na : {a-1, a, a+1}) {
				rep(j, n) nsum[na-(a-1)][In[j] - '0'] += f(na, score[j]);
			}
			FL posi[3] = {};
			rep(j, 3) posi[j] = nsum[j][rv] / (nsum[j][0] + nsum[j][1]);
			a = (a - 1) + (int)(max_element(posi, posi + 3) - posi);
		}
	}
	return 0;
}