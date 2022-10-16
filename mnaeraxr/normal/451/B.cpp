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
bool D[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	cin >> V[0];

	for (int i = 1; i < n; ++i){
		cin >> V[i];
		D[i - 1] = V[i - 1] > V[i];
	}

	int b = -1, e = 0;

	for (int i = 0; i < n - 1; ++i){
		if (D[i]){
			if (b != -1){
				cout << "no" << endl;
				return 0;
			}
			b = i;
			while (i < n - 1 && D[i]) ++i;
			e = i-- + 1;
			if ((e < n && V[b] > V[e]) || (e && b && V[e - 1] < V[b - 1])){
				cout << "no" << endl;
				return 0;
			}
		}
	}

	cout << "yes" << endl;
	if (b == -1){
		cout << "1 1" << endl;
	}
	else{
		cout << b + 1 << " " << e << endl;
	}

	return 0;
}