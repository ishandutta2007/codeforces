#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	if(a[0] == a[n-1]){
		cout << 0 << endl;
		return 0;
	}
	if((a[n-1]-a[0])%2 == 0){
		int m = (a[0]+a[n-1])/2;
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(a[i] != a[0] && a[i] != m && a[i] != a[n-1]) flag = false;
		}
		if(flag){
			cout << m-a[0] << endl;
			return 0;
		}
	}
	
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(a[i] != a[0] && a[i] != a[n-1]) flag = false;
	}
	if(flag){
		cout << a[n-1]-a[0] << endl;
		return 0;
	}
	cout << -1 << endl;
	
	return 0;
}