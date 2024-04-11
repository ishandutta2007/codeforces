/*
 * in the name of god
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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

int n,a[350],pos[350],maxi[350];
int mat[350][350],f[350][350];

int main(){
	
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			cin >> mat[i][j];
			f[i][mat[i][j]] = j;
		}
	for (int i=1; i<=n; i++){
		cin >> a[i]; pos[a[i]]=i;
	}
	maxi[1]=1;
	for (int i=2;i<=n;i++){
		maxi[i]=maxi[i-1];
		if (pos[i]<pos[maxi[i]])
			maxi[i]=i;
	}

	for (int i=1; i<=n; i++){
		int ans=-1;
		for (int j=1; j<=n; j++) if (j!=i){

			int tmp=-1;

			for (int z=1; z<=j; z++) if (z!=i && (tmp==-1 || pos[z]<pos[tmp]))
				tmp=z;

			if (tmp==j){
				if (ans==-1 || f[i][tmp]<f[i][ans])
					ans = tmp;
			}
		}
		cout << ans << ' ';
	}
	cout << endl;

	return 0;
}