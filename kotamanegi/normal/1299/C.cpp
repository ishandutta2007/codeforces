#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}
void solve(){
	int n;
	scanf("%d", &n);
	vector<long double> inputs;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		inputs.push_back(a);
	}
	stack<pair<long double, int>> go;
	for (int i = inputs.size() - 1; i >= 0; --i) {
		go.push(mp(inputs[i], i+1));
		while (go.size() != 1) {
			pair<long double, int> a = go.top();
			go.pop();
			pair<long double, int> b = go.top();
			go.pop();
			long double summing = b.first * (long double)(b.second - a.second) + a.first * (long double)(a.second - i);
			summing /= (long double)(b.second - i);
			if (summing < a.first) {
				go.push(mp(summing, b.second));
			}
			else {
				go.push(b);
				go.push(a);
				break;
			}
		}
	}
	int now = 0;
	while (go.empty() == false) {
		pair<long double, int> hoge = go.top();
		go.pop();
		while (now < hoge.second) {
			inputs[now] = hoge.first;
			now++;
		}
	}
	REP(i, inputs.size()) {
		printf("%.15lf\n", (double)inputs[i]);
	}
}
#undef int
int main() {
	//init();
	solve();
}