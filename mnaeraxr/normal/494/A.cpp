#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int bad(){
	cout << -1 << endl;
	return 0;
}

bool valid(string &s){
	int op = 0;
	for (int i = 0; i < (int)s.length(); ++i){
		if (s[i] == '(')
			op++;
		else{
			op--;
			if (op < 0)
				return false;
		}
	}
	return op == 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	int d = 0, t = 0;

	for (int i = 0; i < (int)s.length(); ++i){
		if (s[i] == '(') d++;
		else if (s[i] == ')') d--;
		else t++;
	}

	if (t > d)
		return bad();

	string c = "";
	int cnt = 0;

	for (int i = 0; i < (int)s.length(); ++i){
		if (s[i] != '#')
			c += s[i];
		else{
			cnt++;
			if (cnt < t)
				c += ')';
			else{
				for (int j = 0; j < d - t + 1; ++j)
					c += ')';
			}
		}
	}

	if (valid(c)){
		//DB(c);
		for (int i = 0; i < t - 1; ++i){
			cout << 1 << endl;
		}
		cout << d - t + 1 << endl;
	}
	else{
		return bad();
	}

	return 0;
}