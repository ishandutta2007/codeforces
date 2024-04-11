#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100000 + 10;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	int ans = ((a + b) % n + n) % n;
	if (ans == 0) ans = n;
	cout << ans << endl;

	return 0;
}