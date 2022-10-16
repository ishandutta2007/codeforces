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

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	int64 k;
	cin >> n >> k;

	vector<int64> value(n);
	
	for (int i = 0; i < n; ++i){
		cin >> value[i];
	}

	int64 m = *min_element( value.begin(), value.end() );

	int64 answer = 0;

	for (int i = 0; i < n; ++i){
		int64 d = value[i] - m;
		
		if (d % k){
			answer = -1;
			break;
		}

		answer += d / k;
	}

	cout << answer << endl;

	return 0;
}