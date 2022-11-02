#include <iostream>
using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	
	char* ch= new char[n];
	cin >> ch;
	for(int i = 0 ; i < t; i++)
	{
		for(int j = 1 ; j < n; j++)
			if ( ch[j-1] == 'B' && ch[j] == 'G' ){
				swap ( ch[j-1] , ch[j] );
				j++;
			}
	}
	for(int i = 0 ;  i < n;i++)
		cout << ch[i];
	cout << endl;
}