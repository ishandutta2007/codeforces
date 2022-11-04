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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 1000+10;

char mat[MAXN][MAXN];
int n;
int row[MAXN],col[MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> mat[i][j];
			row[i]+= (mat[i][j] == 'E');
			col[j]+= (mat[i][j] == 'E');
		}
	}
	int maxR = *max_element(row, row+n);
	int maxC = *max_element(col, col+n);
	if (maxR!=n){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++) if (mat[i][j] != 'E'){
				cout << i+1 << ' ' << j+1 << endl;
				break;
			}
		}
		return 0;
	}
	if (maxC!=n){
		for (int j=0; j<n; j++)
			for (int i=0; i<n; i++) if (mat[i][j] != 'E'){
				cout << i+1 << ' ' << j+1 << endl;
				break;
			}
		return 0;
	}
	cout << -1 << endl;
	return 0;
}