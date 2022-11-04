#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>

using namespace std;

int main(){
	int m, k;
	cin >> m >> k;

	if ( m == 1 && k == 0 )
		cout << 0 << " " << 0;
	else if ( k == 0 || 9*m < k )
		cout << -1 << " " << -1;
	else{
		string s = "";
		int aux = k;

		//Menor
		for( int i = 1; i <= m; i++ ){
			int j = 0;
			for(j; j < 10; j++){
				if ( s.size() > 0 || j > 0 ){
					if ( 9*(m-i) >= k - j ){
						s += j + '0';
						k -= j;
						break;
					}
				}
			}
		}
		cout << s << " ";
		
		//Mayor
		s = "";
		k = aux;
		for( int i = 1; i <= m; i++ ){
			int j = 9;
			for(j; j >=0; j--){
				if ( k - j >= 0 ){
					s += j + '0';
					k -= j;
					break;
				}
			}
		}
		cout << s;
	}

	return 0;
}