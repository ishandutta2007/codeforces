#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e2 + 10;

int V[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	int mx, mn;
	cin >> V[0];
	mx = mn = V[0];
	for (int i = 1; i < n; ++i){
		cin >> V[i];
		mx = max(V[i], mx);
		mn = min(V[i], mn);
	}

	if (mx - mn > k){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i){
			bool start = true;
			for (int j = 0; j < mn; ++j){
				if (start) start = false;
				else cout << " ";
				cout << 1;
			}
			for (int j = mn; j < V[i]; ++j){
				if (start) start = false;
				else cout << " ";
				cout << ((j - mn) % k + 1);
			}
			cout << endl;
		}
	}

	return 0;
}