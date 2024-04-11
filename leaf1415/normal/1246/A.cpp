#include <iostream>
#define llint long long

using namespace std;

llint n, p;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p;
	
	for(int k = 0; k <= 40; k++){
		llint m = n - p * k;
		if(m < 0) continue;
		llint cnt = 0;
		for(llint t = m; t; t/=2) cnt += t % 2;
		if(m >= k && cnt <= k){
			cout << k << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}