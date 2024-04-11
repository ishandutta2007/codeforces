#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const string need = "trygub";

int T;
int n;
int cnt[Maxl];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(cnt, cnt + Maxl, 0);
		string s; cin >> s;
		for (int i = 0; i < s.length(); i++)
			cnt[s[i] - 'a']++;
		string res;
		for (int i = int(need.size()) - 1; i >= 0; i--)
			while (cnt[need[i] - 'a'] > 0) {
				res += need[i];
				cnt[need[i] - 'a']--;
			}
		for (int i = 0; i < Maxl; i++)
			while (cnt[i] > 0) {
				res += 'a' + i;
				cnt[i]--;
			}
		cout << res << endl;
	}
    return 0;
}