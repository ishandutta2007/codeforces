#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;


int main(){
	string s;
	cin >> s;
	int i = 0, j = s.size() - 1;

	int c = 0;
	while( i < j ){
		if ( s[i] != s[j] )
			c++;
		i++; j--;
	}

	if ( c == 1 )
		cout << "YES";
	else if ( s.size() % 2 && c == 0 )
		cout << "YES";
	else
		cout << "NO";

	return 0;
}