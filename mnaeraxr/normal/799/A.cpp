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

	int64 n, t, k, d;
	cin >> n >> t >> k >> d;

	int64 a = (n + k - 1) / k * t;

	int64 t1 = t, t2 = d + t;
	int64 b = 0, f = 0;
	
	while (f < n){
		if (t2 < t1) swap(t1, t2);
		b = t1;
		f += k;
		t1 += t;		
	}

	cout << (b < a ? "YES" : "NO") << endl;

	return 0;
}