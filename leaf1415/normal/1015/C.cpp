#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
llint a[100005], b[100005];
llint d[100005];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < n; i++) d[i] = a[i] - b[i];
	sort(d, d+n);
	reverse(d, d+n);
	
	llint sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];
	
	if(sum <= m){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		sum -= d[i];
		if(sum <= m){
			cout << i+1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}