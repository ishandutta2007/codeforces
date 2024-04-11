#include <iostream>
#define llint long long

using namespace std;

llint n, k;
llint h[200005];
llint num[200005], sum[200005];

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> h[i];
	
	for(int i = 1; i <= n; i++) num[h[i]]++;
	llint x = n;
	for(int i = 0; i < 200005; i++){
		sum[i] = x;
		x -= num[i];
	}
	
	llint ans = 0, s;
	for(int i = 0; i < 200005; i++){
		if(sum[i] < n){
			s = i;
			break;
		}
	}
	
	//for(int i = 0; i <= 10; i++) cout << num[i] << " "; cout << endl;
	//for(int i = 0; i <= 10; i++) cout << sum[i] << " "; cout << endl;
	
	x = 0;
	for(int i = s; i < 200005; i++){
		if(x + sum[i] > k){
			ans++;
			x = sum[i];
		}
		else x += sum[i];
	}
	if(x > 0) ans++;
	
	cout << ans << endl;
	return 0;
}