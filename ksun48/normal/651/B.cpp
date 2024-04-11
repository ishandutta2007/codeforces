#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(b[j] > a[i]){
				ans++;
				b[j] = 0;
				break;
			}
		}
	}
	cout << ans << endl;
}