#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	int ans = 0, t = 1;
	int joker = 0;

	multiset<int> S;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		if (i + 1 == s){
			if (v != 0)
				ans++;
		}
		else{
			if (v == 0){
				joker++;
				ans++;
			}
			else
				S.insert(v);
		}
	}

	while (!S.empty()){
		if (*S.begin() == t){
			S.erase(t++);
		}
		else{
			t++;
			if (joker) joker--;
			else{
				ans++;
				S.erase(S.find(*S.rbegin()));
			}
		}
	}

	cout << ans << endl;

	return 0;
}