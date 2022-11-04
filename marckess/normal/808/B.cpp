#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int main(){
	ll n, k, x; cin >> n >> k;

	ll aux = 0, sum = 0;
	vl v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int i = 0, j = 0; 
	for(j = 0; j < k; j++)
		aux += v[j];

	sum = aux;
	for(int a = 1; a < n - k + 1; a++, i++, j++){
		aux += v[j] - v[i];
		sum += aux;
	}

	printf("%.6lf", ( double(sum) / double(n - k + 1) ) );

}