#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if(n == 4){
		cout << -1 << endl;
		return 0;
	}
	if(k < n+1){
		cout << -1 << endl;
		return 0;
	}
	cout << a << " " << c << " ";
	for(int i = 1; i <= n; i++){
		if(i != a && i != b && i != c && i != d){
			cout << i << " ";
		}
	}
	cout << d << " " << b << " " << endl;
	cout << c << " " << a << " ";
	for(int i = 1; i <= n; i++){
		if(i != a && i != b && i != c && i != d){
			cout << i << " ";
		}
	}
	cout << b << " " << d << " ";
}