#include <iostream>
#include <math.h>

using namespace std;

int q;
int a[1005];
int ans[30];

int Keta(int x)
{
	int ret = 0;
	for(;x;x/=2) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	for(int i = 0; i < q; i++) cin >> a[i];
	
	for(int i = 0; i < q; i++){
		int k = Keta(a[i]);
		if(a[i] != (1<<k)-1){
			cout << (1<<k)-1 << endl;
			continue;
		}
		
		if(ans[k] != 0){
			cout << ans[k] << endl;
			continue;
		}
		
		ans[k] = 1;
		int S = sqrt(1<<k)+1;
		for(int j = 2; j <= S; j++){
			if(a[i]/j < 2) continue;
			if(a[i]%j == 0){
				ans[k] = max(ans[k], j);
				ans[k] = max(ans[k], a[i]/j);
			}
		}
		cout << ans[k] << endl;
	}
	
	return 0;
}