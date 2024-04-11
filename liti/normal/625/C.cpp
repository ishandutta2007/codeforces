//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
#define __sz(x) ((int)(x).size())

const int maxN = 500 + 10; 
int a[maxN][maxN]; 

int main() { 
	int n,k; cin >> n >> k;
	k--; 
	int cnt = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < k ; j++ ) 
			a[i][j] = ++cnt; 
	int sum = 0; 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = k ; j < n ; j++ ) { 
			a[i][j] = ++cnt; 
			if( j == k ) sum += a[i][j]; 
		}
	cout << sum << endl;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < n ; j++ ) 
			cout << a[i][j] << " \n"[j==n-1]; 
}