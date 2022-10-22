#include <iostream>

using namespace std;

int n;
int a[105];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 2; i <= n; i++){
		if(a[i-1] == 1){
			if(a[i] == 2){
				ans += 3;
				if(i >= 3 && a[i-2] == 3) ans--;
			}
			else ans += 4;
		}
		if(a[i-1] == 2){
			if(a[i] == 1) ans += 3;
			else{
				cout << "Infinite" << endl;
				return 0;
			}
		}
		if(a[i-1] == 3){
			if(a[i] == 1) ans += 4;
			else{
				cout << "Infinite" << endl;
				return 0;
			}
		}
	}
	cout << "Finite" << endl;
	cout << ans << endl;
	return 0;
}