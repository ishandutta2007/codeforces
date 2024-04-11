/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 2000 + 5;

char mat[maxN][maxN];
int n;
int r[maxN],c[maxN];

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> n;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			cin >> mat[i][j]; mat[i][j]-='0';
		}

	int ans = 0;

	for (int i=n; i>0; i--)
		for (int j=1; j<i; j++){

			if (r[i]!=c[j])
				mat[i][j] = 1-mat[i][j];
			
			if (mat[i][j]!=0){
				ans++;
				r[i] = 1-r[i];
				c[j] = 1-c[j];
			}
		}

	for (int i=1; i<=n; i++) if (r[i]!=c[i])
		mat[i][i] = 1-mat[i][i];

	memset (r,false,sizeof r);
	memset (c,false,sizeof c);

	for (int i=1; i<=n; i++)
		for (int j=n; j>i; j--){
			
			if (r[i]!=c[j])
				mat[i][j] = 1-mat[i][j];

			if (mat[i][j]!=0){
				ans++;
				r[i] = 1-r[i];
				c[j] = 1-c[j];
			}
		}

	for (int i=1; i<=n; i++){
			
		if (r[i]!=c[i])
			mat[i][i] = 1-mat[i][i];

		if (mat[i][i]!=0)
			ans++;
	}

	cout << ans << endl;

	return 0;
}