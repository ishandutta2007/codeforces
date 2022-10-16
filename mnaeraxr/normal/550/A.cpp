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

bool look(string &s, char a, char b){
	int i = 1;
	int tot = 0;
	for (; i < SZ(s); ++i){
		if (s[i - 1] == a && s[i] == b){
			i += 2;
			tot |= 1;
			break;
		}
	}
	for (; i < SZ(s); ++i){
		if (s[i - 1] == b && s[i] == a){
			tot |= 2;
			break;
		}
	}
	return tot == 3;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	if (look(s, 'A', 'B') || look(s, 'B', 'A'))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}