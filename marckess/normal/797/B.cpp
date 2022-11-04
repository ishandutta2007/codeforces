#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

using namespace std;

int main(){
	int n;
	ll x, sumPar = 0, sumImpar = 0, maxNeg = -1e5, minImpar = 1e5;

	cin >> n;
	while(n--){
		cin >> x;
		if ( x % 2 ){
			if ( x > 0 ){
				sumImpar += x;
				minImpar = min(minImpar,x);
			}else
				maxNeg = max(maxNeg,x);
		}else
			if ( x > 0 )
				sumPar += x;
	}

	if ( sumImpar == 0 )
		cout << maxNeg + sumPar;
	else
		if ( sumImpar % 2 )
			cout << sumImpar + sumPar;
		else{
			if ( maxNeg != -1e5 && -maxNeg < minImpar )
				cout << sumImpar + sumPar + maxNeg;
			else
				cout << sumImpar + sumPar - minImpar;
		}

	return 0;
}