#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<bool> primes(n + 1, true);

	for (int i = 2; i * i <= n; ++i){
		if (!primes[i]) continue;
		for (int j = i * i; j <= n; j += i)
			primes[j] = false;
	}

	vector<int> ans;

	for (int i = 2; i <= n; ++i){
		if (primes[i]){
			int v = i;
			while (v <= n){
				ans.push_back(v);
				v *= i;
			}
		}
	}

	cout << ans.size() << endl;
	for (auto v : ans)
		cout << v << " ";
	cout << endl;

	return 0;
}