#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int stuff[2000];
	for(int i = 0; i < 2000; i++) stuff[i] = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int t = 0;
		cin >> t;
		stuff[t] = 1;
	}
	for(int i = 0; i < 2000; i++){
		if(stuff[i] && stuff[i+1] && stuff[i+2]){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;

}