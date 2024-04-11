#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	int ans = 0;
	for(int i = 0; i < 720720; i++){
	for(int j = 0; j < n; j++){
		if(i % a[j] == b[j]){
			ans++;
			break;
		}

	}
}
	double c = ans;
	c /= 720720;
	cout << c << endl;
}