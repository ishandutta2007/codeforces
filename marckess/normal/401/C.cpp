#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	int n,m;
	cin >> n >> m;

	if ( n > m + 1 || n * 2 + 2 < m ){
		cout << -1;
		return 0;
	}

	while ( n || m ){
		if ( n > m ){
			cout << '0';
			n--;
		}else if ( m > n + 1 ){
			cout << "11";
			m--;
			m--;
			if ( n ){
				cout << "0";
				n--;
			}
		}else{
			cout << "1";
			m--;
		}
	}

	return 0;
}