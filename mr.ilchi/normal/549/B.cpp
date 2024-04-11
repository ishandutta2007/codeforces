#include <bits/stdc++.h>
using namespace std;

bool mark[200];
int n;
int f[200],g[200];
string s[200];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++)
		cin >> f[i];
	while (true){
		bool flag = false;
		for (int i=0; i<n; i++) if (f[i]==g[i]){
			mark[i] = true;
			for (int j=0; j<n; j++) if (s[i][j]=='1')
				g[j]++;
			flag = true;
		}
		if (flag == false)
			break;
	}
	vector<int> ans;
	for (int i=0; i<n; i++) if (mark[i])
		ans.push_back(i);
	cout << ans.size() << endl;
	for (int i=0; i<(int)ans.size(); i++) 
		cout << ans[i]+1 << ' ';
	cout << endl;
	return 0;
}