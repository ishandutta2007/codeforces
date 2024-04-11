#include<bits/stdc++.h>
using namespace std;
string a[3][2];	
int main(){
	cin >> a[1][0] >> a[2][0] >> a[1][1] >> a[2][1];
	for(int i = 0; i < 2; i++){
		a[0][i] = a[1][i] + a[2][i].substr(1,1)+a[2][i].substr(0,1);
		a[0][i].erase(a[0][i].find('X'),1);
	}
	cout << (((a[0][0][0]-a[0][0][1]-a[0][1][0]+a[0][1][1])%3==0) ? "YES\n" : "NO\n");
}