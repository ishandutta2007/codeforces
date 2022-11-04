#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	long long k,i,j,mitad;
	cin >> n >> k;

	i = 1;
	j = pow(2,n) - 1;
	mitad = ( i + j ) / 2;

	while( mitad != k ){
		n--;
		if( k < mitad)
			j = mitad - 1;
		else
			i = mitad + 1;
		mitad = ( i + j ) / 2;
	}

	cout << n;
}