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

	int n, k;
	cin >> n >> k;

	vector<bool> alive(n, true);
	int leader = 0;

	for (int i = 0; i < k; ++i){

		int v; cin >> v; v = (v + 1) % (n - i);
		int p = leader;

		if (v == 0)
			v = n - i;

		while (true){
			if (alive[p]){
				v--;

				if (v == 0){
					cout << p + 1 << " ";
					alive[p] = false;
				}

				if (v == -1){
					leader = p;
					break;
				}
			}

			p = (p + 1) % n;
		}
	}


	cout << endl;

	return 0;
}