#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int y = 0;
	for(int i = 0; i < n; i++){
		string a;
		int b, c;
		cin >> a >> b >> c;
		if(b >= 2400 && c > b){
			y = 1;
		}
	}
	cout << (y ? "YES\n" : "NO\n");
}