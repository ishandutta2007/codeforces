#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

bool open(char c){
	return c == '(' || c == '[' || c == '<' || c == '{';
}

bool close(char c){
	return !open(c);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	stack<char> stk;

	int ans = 0;
	for (auto c : s){
		if (open(c)) stk.push(c);
		else{
			if (stk.empty()){
				cout << "Impossible" << endl;
				exit(0);
			}
			else{
				if (c - stk.top() > 2 || c < stk.top()) ++ans;
				stk.pop();
			}
		}
	}

	if (stk.empty()) cout << ans << endl;
	else cout << "Impossible" << endl;

	return 0;
}