#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef int int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;
const int mod = 1000000007;

int go[maxn];
int wh[maxn];
int pl[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> go[i];

	int total = 0;

	for (int i = 1; i <= n; ++i){
		if (go[ go[i] ] != go[i]){
			cout << -1 << endl;
			return 0;
		}

		if (go[i] == i){
			wh[i] = ++total;
			pl[total] = i;
		}
	}

	cout << total << endl;

	for (int i = 1; i <= n; ++i){
		cout << wh[ go[i] ] << " ";
	}

	cout << endl;

	for (int i = 1; i <= total; ++i)
		cout << pl[i] << " ";

	cout << endl;



	return 0;
}