#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1e-7;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 10;

vi lst[MAXN];
int pnt[MAXN];
int val[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> ans(n);
	for (int i = 1; i <= n; ++i){
		int v; cin >> v;
		val[i] = v;
		lst[v].push_back(i);
	}

	int cur = -1;
	int i = 0;
	while (i < n){
		if (pnt[cur + 1] < SZ(lst[cur + 1])){
			ans[i++] = lst[cur + 1][pnt[cur + 1]++];
			cur++;
			continue;
		}

		cur -= 2;
		while (cur >= 0 && pnt[cur] == SZ(lst[cur])) cur -= 3;
		if (cur < 0) break;
		ans[i++] = lst[cur][pnt[cur]++];
	}

	if (i == n){
		cout << "Possible" << endl;
		for (int i = 0; i < n; ++i)
			cout << ans[i] << " ";
		cout << endl;
//		for (int i = 0; i < n; ++i)
//			cout << val[ans[i]] << " ";
//		cout << endl;
	}
	else{
		cout << "Impossible" << endl;
	}


	return 0;
}