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

int64 freq[2][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	int64 ans1 = 0, ans2 = 0;

	for (int i = 0; i < (int)s.length(); ++i){
		freq[s[i] - 'a'][i & 1]++;
		ans1 += freq[s[i] - 'a'][(i & 1) ^ 1];
		ans2 += freq[s[i] - 'a'][i & 1];
	}
	cout << ans1 << " " << ans2 << endl;

	return 0;
}