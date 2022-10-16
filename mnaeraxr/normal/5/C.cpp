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

	int balance = 0, sz = 0, freq = 1;

	stack<pii> S;
	S.push(MP(0,-1));

	for (int i = 0; i < SZ(s); ++i){
		if (s[i] == '(') ++balance;
		else --balance;

		while (!S.empty() && S.top().first > balance) S.pop();
		if (!S.empty() && s[i] == ')'){
			int v = i - S.top().second;
			if (v > sz) sz = v, freq = 1;
			else if (v == sz) freq++;
		}
		if (S.empty() || S.top().first < balance) S.push(MP(balance, i));
	}

	cout << sz << " " << freq << endl;

	return 0;
}