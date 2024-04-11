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

void end(string s){
	cout << s << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> V(10);
	bool ok = false;
	for (int i = 0; i < 6; ++i){
		int v; cin >> v;
		V[v]++;
		if (V[v] == 4){
			V[v] -= 4;
			ok = true;
		}
	}

	if (!ok){
		cout << "Alien" << endl;
		exit(0);
	}

	int mx = 0;
	for (int i = 0; i < 10; ++i){
		mx = max(V[i], mx);
	}

	if (mx == 2){
		cout << "Elephant" << endl;
	}
	else{
		cout << "Bear" << endl;
	}

	return 0;
}