#include <iostream>
using namespace std;

int main() 
{
	int n; 
	cin >> n ; 

	for(int i =  0; i < n ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			cout << j * n + ( (i + j) % n + 1 ) <<  ' ';	
		}	
		cout << endl;
	}
}