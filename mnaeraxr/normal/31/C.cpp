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

int L[5010], R[5010];

bool intersect(int i, int j){
	if (L[i] <= L[j] && L[j] <= R[i]) return true;
	if (L[i] <= R[j] && R[j] <= R[i]) return true;
	if (L[j] <= L[i] && L[i] <= R[j]) return true;
	if (L[j] <= R[i] && R[i] <= R[j]) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> L[i] >> R[i];
		R[i]--;
	}

	int p1 = -1, p2 = -1;
	bool found = false;
	for (int i = 0; i < n && !found; ++i){
		for (int j = i + 1; j < n && !found; ++j){
			if (intersect(i,j)){
				p1 = i, p2 = j;
				found = true;
			}
		}
	}

	if (p1 == -1){
		cout << n << endl << 1;
		for (int i = 2; i <= n; ++i)
			cout << " " << i;
		cout << endl;
	}
	else{
		int ok1 = 1, ok2 = 1;
		for (int i = 0; i < n && ok1; ++i){
			if (i == p1) continue;
			for (int j = i + 1; j < n && ok1; ++j){
				if (j == p1) continue;
				if (intersect(i,j)) ok1 = 0;
			}
		}

		for (int i = 0; i < n && ok2; ++i){
			if (i == p2) continue;
			for (int j = i + 1; j < n && ok2; ++j){
				if (j == p2) continue;
				if (intersect(i,j)) ok2 = 0;
			}
		}

		cout << ok1 + ok2 << endl;
		if (ok1) cout << p1 + 1;
		if (ok2){
			if (ok1) cout << " " << p2 + 1;
			else cout << p2 + 1;
		}
		cout << endl;
	}

	return 0;
}