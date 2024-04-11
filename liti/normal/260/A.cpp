#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char **argv)
{
	long long int b,n;
	string a;
	cin >> a >> b >> n;
	long long int num = atoi(a.c_str());
	long long int m = num %b;
	if ( m != 0 ){
		m = (m*(10%b))%b;
		if ( m != 0)
			m= b - m;
		
		if ( m < 10 )
			a += (char)(m+ 48);
		else{
			cout << -1 << endl;
			return 0;
		}
		n--;
	}
	for(int i = 0; i < n; i++)
		a+= "0";
	cout << a << endl;
	return 0;
}