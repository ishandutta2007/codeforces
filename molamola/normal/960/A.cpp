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

char A[5050];

void solve() {
	scanf("%s", A);
	int L = (int)strlen(A);
	if(!is_sorted(A, A+L)) puts("NO");
	else {
		if(A[0] != 'a' || A[L-1] != 'c') puts("NO");
		else {
			int cnt[3] = {};
			rep(i, L) cnt[A[i] - 'a']++;
			if(cnt[0] >= 1 && cnt[1] >= 1 && (cnt[2] == cnt[0] || cnt[2] == cnt[1])) {
				puts("YES");
			}
			else puts("NO");
		}
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}