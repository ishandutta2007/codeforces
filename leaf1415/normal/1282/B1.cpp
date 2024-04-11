#include <iostream>
#include <cstdlib>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint n, p, k;
llint a[200005];
llint sum[200005], sumk[200005];

bool check(llint x)
{
	llint ret = sumk[x];
	ret += sum[x%k];
	return ret <= p;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> p >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		
		for(int i = 1; i <= n; i++){
			sum[i] = sum[i-1] + a[i];
			if(i >= k) sumk[i] = sumk[i-k] + a[i];
			else sumk[i] = 0;
		}
		
		//for(int i = 0; i <= n; i++) cout << sumk[i] << " ";  cout << endl;
		
		llint ans = 0;
		for(int i = 1; i <= n; i++){
			if(check(i)) ans = i;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}