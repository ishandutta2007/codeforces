/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int arr[11][11];
	arr[0][0] = 1;
	int n; cin >> n;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if(!i || !j) { arr[i][j] = 1; }
			else { arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]); }
		}
	}
	cout << arr[n -1][n - 1] << endl;
}