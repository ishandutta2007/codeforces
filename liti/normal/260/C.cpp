#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	long long int n,x;
	cin >> n >> x;
	long long int a[n];
	cin >> a[0];
	long long int min = a[0];
	long long int minId = 0;
	for(long long int i = 1;i < n; i++){
		cin >> a[i];
		if ( a[i] < min ) {
			min = a[i];
			minId = i;
		}
		if ( a[i] == min && i < x )
		{
			min = a[i];
			minId = i;
		}
		if ( a[i] == min && minId >= x && i > minId ){
			min = a[i];
			minId = i;
		}
	}
	
	x = x -1 ;
	
	long long int z = min;
	if ( minId <= x )
		z--;
	///cout << z << minId << x << endl;
	for(long long int i = 0; i < n; i++){
		a[i] -= z;
		if ( i > minId ) 
			a[i]--;
		if ( i <= x )
			a[i]--;
		if ( i == minId ){
			a[minId] = z * n + x + 1 + (n - minId - 1);

		}

		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}