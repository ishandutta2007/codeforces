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

int n, k;
int A[50050][12];

struct str{
	int z;
	vector <int> mn;
	vector <int> mx;
	bool operator<(const str &r) const {
		return mn[0] < r.mn[0];
	}
};

set <str> S;

int chk(str A, str B) {
	int a = 3;
	rep(i, k) {
		if(!(A.mn[i] > B.mx[i])) a &= 2;
		if(!(B.mn[i] > A.mx[i])) a &= 1;
	}
	return !!a;
}

void solve() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) scanf("%d", A[i]+j);
	for(int i=1;i<=n;i++) {
		str X; X.z = 1;
		rep(a, k) X.mn.push_back(A[i][a+1]);
		rep(a, k) X.mx.push_back(A[i][a+1]);
		auto it = S.lower_bound(X);
		auto jt = it;
		vector <str> er;
		while(1) {
			if(it == S.end()) break;
			if(chk(*it, X)) break;
			
			er.pb(*it);
			++it;
		}
		if(jt != S.begin()) {
			--jt;
			while(1) {
				if(chk(*jt, X)) break;
				er.pb(*jt);
				if(jt == S.begin()) break;
				--jt;
			}
		}
		for(auto ele : er) {
			rep(i, k) X.mn[i] = min(X.mn[i], ele.mn[i]), X.mx[i] = max(X.mx[i], ele.mx[i]);
			X.z += ele.z;
			S.erase(ele);
		}
		S.insert(X);
		printf("%d\n", (S.rbegin()) -> z);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case %d: ", tc);
		solve();
	}
	return 0;
}