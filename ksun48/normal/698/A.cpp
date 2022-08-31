#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	int c1 = 0;
	int c2 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 3){
			ans++;
			if(c1 == 0 && c2 == 0){
				c1 = c2 = 0;
			} else if(c1 == 1){
				c1 = 0;
				c2 = 1;
			} else if(c2 == 1){
				c1 = 1;
				c2 = 0;
			}
		} else if(a[i] == 2){
			if(c2 == 1){
				c2 = 0;
			} else {
				c2 = 1;
				c1 = 0;
				ans++;
			}
		} else if(a[i] == 1){
			if(c1 == 1){
				c1 = 0;
			} else {
				c1 = 1;
				c2 = 0;
				ans++;
			}
		} else {
			c1 = c2 = 0;
		}
	}
	cout << n- ans << endl;
}