#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

char M[200][200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){

			M[i][j] = 'S';

			if (k){

				M[i][j] = 'L';

				if (i && M[i - 1][j] == 'L')
					M[i][j] = 'S';

				if (j && M[i][j - 1] == 'L')
					M[i][j] = 'S';

				k -= (M[i][j] == 'L');
			}
		}


	if (k) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << M[i][j];
			cout << endl;
		}
	}


	return 0;
}