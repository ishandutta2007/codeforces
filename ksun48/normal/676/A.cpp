#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int c = 0;
	int d = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a == 1){
			c = i;
		} else if(a == n){
			d = i;
		}
	}
	cout << max(max(c,d),max(n-1-c,n-1-d)) << endl;
}