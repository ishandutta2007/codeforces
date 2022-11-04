#include <bits/stdc++.h>
using namespace std;

int a[100];
long long n,m;

int main(){
	cin >> n >> m;
	int lo = 0, hi = n-1;
	for (int i=0; i<n; i++){
		if (m <= (1LL<<(n-i-2)))
			a[lo++] = i+1;
		else{
			m-= (1LL<<(n-i-2));
			a[hi--] = i+1;
		}
	}
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}