#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>

using namespace std;

int main(){
	int a, b, c=0;
	cin >> a >> b;
	while( a <= b ){
		a *=3;
		b *= 2;
		c++;
	}

	cout << c;
	
	return 0;
}