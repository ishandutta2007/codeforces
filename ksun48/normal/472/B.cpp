#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	cin >> n >> k;
	int f[n];
	for(int i = 0; i < n; i++){
		cin >> f[i];
		f[i] = -f[i];
	}
	sort(f, f+n);
	for(int i = 0; i < n; i++){
		f[i] = -f[i];
	}
	int answer = 0;
	for(int i = 0; i < n; i+= k){
		answer += (f[i]-1)*2;
	}
	cout << answer << endl;


}