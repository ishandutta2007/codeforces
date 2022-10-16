#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)3e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<bool> mk(n);
	int ans = 0;
	for (int i = 0; i < 2; ++i){
		int v; cin >> v;
		for (int j = 0; j < v; ++j){
			int w; cin >> w;
			if (!mk[w - 1]){
				++ans;
				mk[w - 1] = true;
			}
		}
	}
	if (ans == n) cout << "I become the guy." << endl;
	else cout << "Oh, my keyboard!" << endl;
	
	return 0;
}