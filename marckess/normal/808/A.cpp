#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int main(){
	int n;
	int res = 1, k = 0, aux;

 	cin >> aux;
 	n = aux;

	while( n > 9 ){
		res *= 10;
		n /= 10;
	}

	n = aux;
	k = n % res;

	cout << res - k % res;

}