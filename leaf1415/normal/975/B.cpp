#include <iostream>
#define llint long long

using namespace std;

llint a[14];

int main(void)
{
	for(int i = 0; i < 14; i++) cin >> a[i];
	
	llint ans = 0, tmp[14];
	for(int i = 0; i < 14; i++){
		if(a[i] == 0) continue;
		for(int j = 0; j < 14; j++) tmp[j] = a[j];
		
		llint n = a[i];
		tmp[i] = 0;
		for(int j = 0; j < 14; j++) tmp[j] += n / 14;
		for(int j = 1; j <= n % 14; j++){
			tmp[(i+j)%14]++;
		}
		
		n = 0;
		for(int j = 0; j < 14; j++){
			if(tmp[j]%2 == 0) n += tmp[j];
		}
		ans = max(ans, n);
	}
	cout << ans << endl;
	
	return 0;
}