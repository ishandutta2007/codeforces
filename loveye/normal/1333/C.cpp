#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int n,a[N],s[N],ans,minl = -1;
map<int,int> maxl;
signed main() {
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i],s[i] = s[i-1] + a[i];
	maxl[0] = 0;
	for(int i = 1;i <= n;++i) {
		if(!maxl.count(s[i])) maxl[s[i]] = -1;
		minl = max(minl,maxl[s[i]]);
		maxl[s[i]] = i;
		ans += i-1 - minl;
	}
	cout << ans << endl;
	return 0;
}