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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (i % 2 == 0 || (i % 4 == 1 && j + 1 == m) || (i % 4 == 3 && j == 0)){
				putchar('#');
			}
			else{
				putchar('.');
			}
		}
		putchar('\n');
	}

	return 0;
}