#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	
	cin >> n;
	if(n%2)cout << (n + 2) * (n + 2) / 2 << '\n';
 	else cout << pow((n/2+1), 2) << '\n';


	return 0;
}