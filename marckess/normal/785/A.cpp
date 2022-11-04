#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	int n, count = 0;
	string s;
	cin >> n;
	while( n-- ){
		cin >> s;
		if (s == "Tetrahedron")
			count += 4;
		if (s == "Cube")
			count += 6;
		if (s == "Octahedron")
			count += 8;
		if (s == "Dodecahedron")
			count += 12;
		if (s == "Icosahedron")
			count += 20;
	}
	cout << count;
	return 0;
}