#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string a,b,c;
	long long la,lb,lc;
	ostringstream aux;
	cin >> a >> b;

	istringstream(a) >> la;
	istringstream(b) >> lb;
	lc = la + lb;
	aux << lc;
	c = aux.str();

	while( a.find('0') != string::npos )
		a.erase(a.find('0'),1);
	while( b.find('0') != string::npos )
		b.erase(b.find('0'),1);
	while( c.find('0') != string::npos )
		c.erase(c.find('0'),1);

	istringstream(a) >> la;
	istringstream(b) >> lb;
	istringstream(c) >> lc;

	if(la + lb == lc)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}