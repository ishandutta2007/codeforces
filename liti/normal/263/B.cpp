#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long int n,k;
	cin >> n >> k;
	long long int a[n];
	for(long long int i = 0 ; i < n;i++)
		cin >> a[i];
	sort(a,a + n );
	if ( k > n )
		cout << "-1" << endl;
	else
		cout << a[n - k] << " " <<  a[n-k] << endl;
}