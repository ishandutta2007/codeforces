#include <iostream>

using namespace std;

int n;
int a[200005];
int ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ub = 200005, lb = -1;
	for(int i = 1; i <= n-1; i++){
		if(a[i] <= a[i+1]){
			if(lb < a[i]){
				ans[i] = 0, lb = a[i];
			}
			else if(ub > a[i]){
				ans[i] = 1, ub = a[i];
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
		else if(a[i] > a[i+1]){
			if(ub > a[i]){
				ans[i] = 1, ub = a[i];
			}
			else if(lb < a[i]){
				ans[i] = 0, lb = a[i];
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	if(lb < a[n]){
		ans[n] = 0, lb = a[n];
	}
	else if(ub > a[n]){
		ans[n] = 1, ub = a[n];
	}
	else{
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}