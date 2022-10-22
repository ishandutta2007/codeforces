#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,a[N];
bool vis[N];
int main() {
	int T;
	cin >> T;
	while(T--) {
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	memset(vis,0,sizeof vis);
	int ans = 0;
	for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j)
		if(!vis[abs(a[i]-a[j])]) vis[abs(a[i]-a[j])] = 1,++ans;
	if(vis[0]) --ans;
	cout << ans <<endl;
	}
	return 0;
}