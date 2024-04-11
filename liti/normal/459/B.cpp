/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 2000*100 + 10;

map<int,int> val;
int a[maxN];

int main() { 
	int n;
	cin >> n;

	for(int i =0 ; i  < n ; i++ ) {
		cin >> a[i];
		val[a[i]]++;
	}

	sort( a , a + n );
	n = unique( a , a + n ) - a ; 

	cout << a[n-1] - a[0] << ' ' ;
	if( n == 1 ) 
		cout << 1LL*val[a[0]]*(val[a[0]]-1 ) / 2 << endl;
	else
		cout << 1LL*val[a[0]]*val[a[n-1]] << endl;
}