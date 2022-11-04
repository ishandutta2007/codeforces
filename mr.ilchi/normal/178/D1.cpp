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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n;
int a[100];
int mat[10][10];

int main(){
	
	cin >> n;

	int sum = 0;

	for (int i=1; i<=n*n; i++){
		cin >> a[i];
		sum+= a[i];
	}

	sum/=n;

	sort(a+1,a+n*n+1);

	do{

		int poi = 1;

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++){
				mat[i][j] = a[poi];
				poi++;
			}

		bool f = false;

		for (int i=1; i<=n; i++){
			int tmp = 0;
			int tmp2= 0;
			for (int j=1; j<=n; j++){
				tmp+= mat[i][j];
				tmp2+= mat[j][i];
			}
			if (tmp!=sum || tmp2!=sum){
				f = true;
				break;
			}
		}

		int tmp=0,tmp2=0;
		for (int i=1; i<=n; i++){
			tmp += mat[i][i];
			tmp2+= mat[i][n+1-i]; 
		}

		if (tmp!=sum || tmp2!=sum)
			f = true;

		if (!f){
			cout << sum << endl;
			for (int i=1; i<=n; i++){
				for (int j=1; j<=n; j++){
					cout << mat[i][j] << ' ';
				}
				cout << endl;
			}
			return 0;
		}

	}while(next_permutation(a+1,a+n*n+1));

	return 0;
}