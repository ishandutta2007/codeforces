#include <iostream>
#include <stdlib.h>

using namespace std;

int n;
int a[1005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 1e9, ans_i, tmp;
	for(int i = 1; i <= 100; i++){
		tmp = 0;
		for(int j = 1; j <= n; j++){
			if(i+1 < a[j]) tmp += a[j]-(i+1);
			if(i-1 > a[j]) tmp += (i-1)-a[j];
		}
		if(ans > tmp){
			ans = tmp;
			ans_i = i;
		}
	}
	cout << ans_i << " " << ans << endl;
	return 0;
}