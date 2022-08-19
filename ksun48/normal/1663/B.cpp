#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int x;
	cin >> x;
	for(int a : {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000}){
		if(a > x){
			cout << a << '\n';
			break;
		}
	}
}