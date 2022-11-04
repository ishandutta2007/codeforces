#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll>

using namespace std;

int main(){
	int n, a, b, x, fi[1002], se[1002];
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> fi[i] >> se[i];
		if ( fi[i] != se[i] ){
			cout << "rated";
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if ( fi[i] < fi[j] ){
				cout << "unrated";
				return 0;
			}
		}
	}

	cout << "maybe";

}