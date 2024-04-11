#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> A, B;

	int m; cin >> m;

	for (int i = 0; i < m; ++i){
		int v; cin >> v;
		string s; cin >> s;

		if (s[0] == 'U') A.push_back(v);
		else B.push_back(v);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int pa = 0, pb = 0;
	int64 cost = 0, tot = 0;

	while (pa < (int)A.size() && a){
		cost += A[pa++];
		tot++;
		a--;
	}

	while (pb < (int)B.size() && b){
		cost += B[pb++];
		tot++;
		b--;
	}

	while (c){
		int64 ca = oo, cb = oo;

		if (pa < (int)A.size())
			ca = A[pa];

		if (pb < (int)B.size())
			cb = B[pb];

		if (min(ca, cb) < oo){
			if (ca <= cb){
				cost += ca;
				pa++;
			}
			else{
				cost += cb;
				pb++;
			}
			tot++;
			c--;
		}
		else
			break;
	}

	cout << tot << " " << cost << endl;

	return 0;
}