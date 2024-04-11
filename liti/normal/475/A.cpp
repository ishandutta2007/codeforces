/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

string a[] = { "+------------------------+" , 
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)" , 
	"|#.#.#.#.#.#.#.#.#.#.#.|.|" , 
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+" } ; 

int main() { 
	int k;
	cin >> k ; 

	for( int t = 0 ; t < k ; t++ ) { 
		for( int j = 0 ; j < 24 ; j++ ) 
			for( int i = 0 ; i < 6 ; i++ ) 
				if( a[i][j] == '#' ) { 
					a[i][j] = 'O';
					goto HELL;
				}
HELL:
		t=t;
	}
	for( int i = 0 ; i < 6 ; i++ ) 
		cout << a[i] << endl;
}