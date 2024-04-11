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

	string s;
	cin >> s;

	if (s[0] == '@' || s[SZ(s) - 1] == '@')
	{
		cout << "No solution" << endl;
		exit(0);
	}

	vector<int> V;
	for (int i = 0; i < SZ(s); ++i){
		if (s[i] == '@'){
			if (!V.empty() && (i - V[SZ(V) - 1] <= 2)){
				cout << "No solution" << endl;
				exit(0);
			}
			V.push_back(i);
		}
	}

	if (V.empty())
	{
		cout << "No solution" << endl;
		exit(0);
	}

	int cur = 0;
	for (int i = 0; i < SZ(V); ++i){
		if (cur) cout << ",";

		if (i + 1 == SZ(V))
			cout << s.substr(cur, SZ(s) - cur);
		else
			cout << s.substr(cur, V[i] + 2 - cur);
		cur = V[i] + 2;
	}
	cout << endl;

	return 0;
}