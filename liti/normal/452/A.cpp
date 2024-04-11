/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

string a[8] = {
	"vaporeon", "jolteon", "flareon", "espeon" , "umbreon", "leafeon", "glaceon", "sylveon"
};

bool check[8];

int main() { 
	int n;
	cin >> n;
	string s;
	cin >> s;

	for(int i =0 ; i < 8 ; i++ ) 
		check[i] |= ( a[i].size() != s.size() ) ; 
	for(int i = 0 ; i < 8 ; i++ ) 
		if( !check[i] ) 
			for(int j = 0 ; j < s.size() ; j++ ) 
				if( s[j] != '.' ) 
					check[i] |= ( s[j] != a[i][j] ) ; 
	for(int i =0 ; i< 8 ; i++ ) 
		if(!check[i] ) 
			cout<< a[i] << endl;
}