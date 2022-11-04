#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, chk[111], fl2;
string s[111], ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> s[i];

	for(int i=1;i<=n;i++){
		if(chk[i]) continue;
		string b = s[i];
		for(int j=0;j<m/2;j++) swap(s[i][j], s[i][m-j-1]);
		for(int j=1;j<=n;j++){
			if(i == j || chk[i] || chk[j]) continue;
			if(s[i] == s[j]){
				ans += s[i];
				chk[i] = chk[j] = 1;
			}
		}
		s[i] = b;
	}

	for(int i=1;i<=n;i++){
		if(chk[i]) continue;
		int fl = 0;
		for(int j=0;j<m/2;j++) if(s[i][j] != s[i][m-j-1]) fl = 1;
		if(!fl){
			fl2 = i;
			break;
		}
	}
	cout << ans.size() * 2 + (fl2 ? m : 0) << '\n';
	cout << ans;
	if(fl2) cout << s[fl2];
	reverse(&ans[0], &ans[ans.size()]);
	cout << ans;
}