#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

llint n, k;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	llint rem = k, m = a[n/2];
	for(int i = n/2+1; i < n; i++){
		if(rem == 0) break;
		llint len = i-n/2, dif = a[i] - m;
		if(len * dif <= rem){
			rem -= len * dif;
			m += dif;
		}
		else{
			m += rem / len;
			rem = 0;
		}
		//cout << rem << " " << m << endl;
	}
	if(rem > 0) m += rem / (n-n/2);
	cout << m << endl;
	
	return 0;
}