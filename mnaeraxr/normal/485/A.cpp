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

bool mk[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, m;
	cin >> a >> m;
	while (true){
		mk[a] = true;
		a <<= 1;
		a %= m;
		if (mk[a]){
			cout << "No" << endl;
			return 0;
		}
		if (a == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}

	return 0;
}