#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

using namespace std;

int main(){
	int n, k, x = 2;
	cin >> n >> k;
	vi res;
	while( n > 1 && k ){
		if ( k == 1 ){
			res.push_back(n);
			k--;
		} else if ( n % x == 0 ){
			res.push_back(x);
			n /= x;
			k--;
		}else
			x++;
	}

	if (k)
		cout << -1;
	else
		for(int i = 0; i < res.size(); i++)
			cout << res[i] << " ";

	return 0;
}