#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[200005], b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	bool flag = false;
	for(int i = 1; i < n; i++){
		if(a[i-1] < a[i]){
			if(flag){
				cout << "NO" << endl;
				return 0;
			}
		}
		if(a[i-1] > a[i]){
			if(!flag) flag = true;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}