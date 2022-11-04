#include <bits/stdc++.h>

//#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;

int main(){
	string x, y, z = "";

	cin >> x >> y;

	for(int i = 0; i < x.size(); i++){
		if ( x[i] == y[i] )
			z += x[i];
		else if ( x[i] > y[i] )
			z += y[i];
		else{
			cout << -1;
			return 0;
		}
	}

	cout << z;

	return 0;
}