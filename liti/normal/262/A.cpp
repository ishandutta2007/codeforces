#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int counter = 0;
	while(n--)
	{
		long long int num ;
		cin >> num;
		int s = 0;
		while(num!=0){
			int d = num % 10;
			if ( d == 4 || d == 7 )
				s++;
			num/=10;
		}
		if ( s <= k ) 
			counter++;

	}
	cout << counter << endl;
}