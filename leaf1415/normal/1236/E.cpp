#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
llint a[100005];
vector<llint> vec[100005];
llint b[200005];

llint calc()
{
	for(int i = 1; i <= n; i++) vec[i].clear();
	for(int i = 1; i <= m; i++) vec[a[i]].push_back(i);
	
	for(int i = 0; i <= n+m+1; i++){
		if(i < n) b[i] = 1;
		else b[i] = 0;
	}
	llint ret = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < vec[i].size(); j++){
			llint x = vec[i][j];
			b[n+x-i+1] += b[n+x-i];
			b[n+x-i] = 0;
		}
		ret += b[n+(m+1)-i] * i;
		//for(int j = 0; j <= n+m+1; j++) cout << b[j] << " "; cout << endl;
	}
	for(int i = 0; i <= m; i++) ret += b[i] * n;
	ret -= n*(n+1)/2;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = calc();
	reverse(a+1, a+m+1);
	ans += calc();
	ans += n;
	
	cout << ans << endl;
	
	return 0;
}