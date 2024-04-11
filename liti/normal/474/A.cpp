/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

int main() { 
	string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char ch;
	cin >> ch;
	string a;
	cin >> a;

	for( int i =0 ; i < a.size() ; i++ ) 
		cout << *( find(s.begin() , s.end() , a[i]) + ( ch == 'R'? -1 : 1 ) ) ;
	cout << endl;
}