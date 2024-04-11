#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int k = (n+1)/2;
	for(int i = 0; i < k; i++){
		if(i < n){
			cout << a[i] << " ";
		}
		if(i+k < n){
			cout << a[i+k] << " ";
		}
	}
	cout << endl;
}