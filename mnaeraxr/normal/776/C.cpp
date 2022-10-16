#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 100000000000000000LL;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int64 k;

	cin >> n >> k;

	vector<int64> C(1, 1);

	if (abs(k) == 1){
		if (k == -1){
			C.push_back(-1);
		}
	}else{
		while ( abs(C.back() * k) <= oo){
			int64 v = C.back() * k;
			C.push_back(v);
		}
	}

	int64 answer = 0;
	int64 sum = 0;

	map<int64, int64> freq;
	freq[0] = 1;

	for (int i = 0; i < n; ++i){
		int64 v; cin >> v;
		sum += v;

		for (auto c : C){
			int64 cur = sum - c;
			if (freq.count(cur)){
				answer += freq[cur];
			}
		}

		freq[sum]++;
	}

	cout << answer << endl;

	return 0;
}