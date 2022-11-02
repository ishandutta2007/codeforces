#include <iostream>
using namespace std;

int main(){
	long n,k;
	cin >> n >> k;
	long long a[n];
	long index=0;
	int l = -1;
	for(int i = 0;i < n;i++)
		cin >> a[i];

	for(int j = k; j > 0 ; j--)
	{
		if ( a[index] == 0 )
			break;
		if ( a[index] > 0 ){
			if ( j % 2 == 0 )
				break;
			else{
				int min = a[index];
				for(int i =0 ;i < n;i++)
					if ( a[i] > 0 && a[i] < min )
					{
						min = a[i];
						index = i;
					}

				a[index] = -a[index];
				break;
			}
		}

		if ( a[index] < 0 ) 
		{
			a[index] =- a[index];
			index++;
		}
		if ( index == n ) 
			index = 0;
	}
	long long sum = 0;
	for(int i = 0 ;i < n;i++)
		sum += a[i] ;
	cout <<sum << endl;
}