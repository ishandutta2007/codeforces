#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<int> v(n);
	vector<int> p(n);

	for (int i = 0; i < n; ++i){
		cin >> v[i]; p[i] = i;
		v[i] = abs(v[i]);
	}

	auto compare = [&](int a, int b){
		return v[a] > v[b];
	};

	sort(p.begin(), p.end(), compare);

	int answer = 0;

	for (int i = 0; i < n; ++i){
		int left = 0, right = 0;

		for (int j = 0; j < n; ++j){
			if (v[j] < v[i]){
				if (j < i) left++;
				else right++;
			}
		}

		answer += min(left, right);
	}

	cout << answer << endl;

	return 0;
}