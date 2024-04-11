#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << "2\n";
		if(n == 2){
			cout << "1 2\n";
		}else{
			cout << n << " " << n - 2 << '\n' << n - 1 << " " << n - 1 << '\n';
			n--;
			for(;n > 2; n--)
				cout << n << " " << n - 2 << '\n';
		}
		
	}
}