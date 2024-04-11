#include <iostream>

using namespace std;

int n, M;
int a[100005];
int sum[100005];

int main(void)
{
	cin >> n >> M;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	if(n % 2 == 0){
		n++;
		a[n] = M;
	}
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0) sum[i] = sum[i-1];
		else sum[i] = sum[i-1] + a[i] - a[i-1];
	}
	
	int ans = sum[n];
	for(int i = 1; i <= n; i += 2){
		ans = max(ans, sum[i]-1 + (M-a[i])-(sum[n]-sum[i]));
	}
	cout << ans << endl;
	return 0;
}