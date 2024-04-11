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
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int MAGIC = 20000000;

	int n; cin >> n;

	queue<int> Q1, Q2;

	int k1; cin >> k1;
	for (int i = 0; i < k1; ++i){
		int v; cin >> v;
		Q1.push(v);
	}

	int k2; cin >> k2;
	for (int i = 0; i < k2; ++i){
		int v; cin >> v;
		Q2.push(v);

	}

	for (int i = 1; i <= MAGIC; ++i){
		int p1 = Q1.front(); Q1.pop();
		int p2 = Q2.front(); Q2.pop();

		if (p1 > p2){
			Q1.push(p2); Q1.push(p1);
		}
		else{
			Q2.push(p1); Q2.push(p2);
		}

		if (Q1.empty()){
			cout << i << " " << 2 << endl;
			exit(0);
		}
		else if (Q2.empty()){
			cout << i << " " << 1 << endl;
			exit(0);
		}
	}

	cout << -1 << endl;

	return 0;
}