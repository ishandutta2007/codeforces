#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int p = 1, t = 1;
	while (p <= n){
		++t;
		p += t * (t + 1) / 2;		 
	}	

	cout << t - 1 << endl;

	return 0;
}