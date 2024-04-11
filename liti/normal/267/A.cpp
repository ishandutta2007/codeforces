#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while ( n-- )
	{
		long long int seq = 0;

		long long int a,b;
		cin >> a >> b;
		while ( a != 0 && b != 0 )
		{
			if ( b > a ) 
				swap ( a, b);
			long long int s = a / b ;
			seq += s;
			a -= (a / b)*b;
		}
		cout << seq << endl;
	}
}