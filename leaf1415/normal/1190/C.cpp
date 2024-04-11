#include <iostream>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>

#define llint long long
#define inf 1e9

using namespace std;
typedef pair<llint, llint> P;

llint n, k;
string s;
llint l0, r0, l1, r1;

bool check(string &t)
{
	bool flag0 = false, flag1 = false;
	l0 = inf, r0 = -inf, l1 = inf, r1 = -inf;
	for(llint i = 0; i < n; i++){
		if(t[i] == '0') flag0 = true, l0 = min(l0, i), r0 = max(r0, i);
		else flag1 = true, l1 = min(l1, i), r1 = max(r1, i);
	}
	return !flag0 || !flag1 || r0-l0+1 <= k || r1-l1+1 <= k;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

	cin >> n >> k;
	cin >> s;

	if(check(s)){
		cout << "tokitsukaze" << endl;
		return 0;
	}

	bool ans = false;
	if(r0-l0+1 >= k+2 || r1-l1+1 >= k+2) ans = true;

	string t = s;
	for(int i = 0; i < k; i++) t[i] = '0';
	ans |= !check(t);

	t = s;
	for(int i = 0; i < k; i++) t[i] = '1';
	ans |= !check(t);

	t = s;
	for(int i = n-k; i < n; i++) t[i] = '0';
	ans |= !check(t);

	t = s;
	for(int i = n-k; i < n; i++) t[i] = '1';
	ans |= !check(t);

	if(ans) cout << "once again" << endl;
	else cout << "quailty" << endl;

  return 0;
}