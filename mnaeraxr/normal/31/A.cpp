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
const int MAXN = (int)1e5 + 10;

int V[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> V[i];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (i == j) continue;
			for (int k = 0; k < n; ++k){
				if (i == k) continue;
				if (j == k) continue;
				if (V[i] + V[j] == V[k]){
					cout << k + 1 << " " << j + 1 << " " << i + 1 << endl;
					exit(0);
				}
			}
		}
	}
	cout << -1 << endl;

	return 0;
}