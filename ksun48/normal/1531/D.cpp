#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	int q;
	cin >> q;
	set<int> locks;
	locks.insert(n);
	set<int> good_unlock;
	good_unlock.insert(-1);
	for(int i = 0; i < n; i++){
		if(s[i] == "lock" || s[i] == "unlock") locks.insert(i);
		if(i+1 < n && s[i] == "unlock" && s[i+1] != "lock" && s[i+1] != "unlock") good_unlock.insert(i);
	}
	for(int z = 0; z <= q; z++){
		int v = *good_unlock.rbegin();
		int w = *locks.upper_bound(v);
		cout << (w == 0 ? "blue" : s[w-1]) << '\n';
		if(z == q) break;
		int i;
		string x;
		cin >> i >> x;
		i--;
		locks.erase(i);
		good_unlock.erase(i);
		if(i > 0) good_unlock.erase(i-1);
		s[i] = x;
		if(s[i] == "lock" || s[i] == "unlock") locks.insert(i);
		if(i+1 < n && s[i] == "unlock" && s[i+1] != "lock" && s[i+1] != "unlock") good_unlock.insert(i);
		if(i-1 >= 0 && s[i-1] == "unlock" && s[i] != "lock" && s[i] != "unlock") good_unlock.insert(i-1);
	}
}