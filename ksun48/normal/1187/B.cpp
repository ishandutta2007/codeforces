#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int> > where(26, {0});
	vector<int> freq(26);
	for(int i = 0; i < n; i++){
		int c = s[i] - 'a';
		freq[c]++;
		where[c].push_back(i+1);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		string a;
		cin >> a;
		vector<int> cfreq(26, 0);
		for(char c : a) cfreq[c-'a']++;
		int res = 0;
		for(int j = 0; j < 26; j++){
			res = max(res, where[j][cfreq[j]]);
		}
		cout << res << '\n';
	}
}