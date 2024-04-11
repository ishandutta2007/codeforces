#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#define llint long long

using namespace std;

llint n, m;
llint x[200005];
llint dif[200005], sum[200005];
llint dif2[200005], sum2[200005];

void add(llint d[], llint l, llint r, llint x)
{
	if(l > r) return;
	d[l] += x, d[r+1] -= x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> x[i];
	
	for(int i = 1; i < m; i++){
		llint l = x[i], r = x[i+1];
		if(l > r) swap(l, r);
		if(l == r) continue;
		add(dif, l, l, r-1);
		add(dif, r, r, (l+1)-1);
		add(dif, l+1, r-1, r-l-1);
		add(dif, 1, l-1, r-l);
		add(dif, r+1, n, r-l);
		//for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + dif[i];
		//for(int i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
	}
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + dif[i];
	for(llint i = 1; i <= n; i++){
		cout << sum[i] << " "; 
	}
	cout << endl;
	
	return 0;
}