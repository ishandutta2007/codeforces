/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

vector<int> a[3];

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n; i++ ){ 
		int num;
		cin >> num;
		a[num-1].push_back( i + 1 ) ; 
	}

	int ans =  min( a[0].size() , min( a[1].size() , a[2].size() ) ) ; 
	cout << ans << endl;
	for( int i = 0 ; i < ans ; i++ ) 
		cout << a[0][i] << ' ' << a[1][i] << ' ' << a[2][i] << endl;
}