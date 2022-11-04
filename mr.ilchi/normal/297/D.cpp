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

int n,m,k;
int a[2000][2000];
string s[1<<20];

int main(){
	cin >> n >> m >> k;
	for (int i=0; i<2*n-1; i++)
		cin >> s[i];
	if (k==1){
		int c = 0;
		for (int i=0; i<2*n-1; i++)
			c+= count(s[i].begin(), s[i].end(), 'E');
		int tot = 2*n*m - n - m;
		if (4*c < tot*3){
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=m; j++)
				cout << 1 << ' ';
			cout << endl;
		}
		return 0;
	}
	if (n<=m){
		for (int i=0; i<n; i++){
			int f = 1;
			for (int j=0; j<m; j++){
				a[i][j] = f;
				if (j!=m-1 && s[2*i][j]=='N')
					f = 3-f;
			}
			if (i!=0){
				int balance = 0;
				for (int j=0; j<m; j++){
					if (a[i][j]==a[i-1][j] && s[2*i-1][j]=='E')
						balance++;
					else if (a[i][j]!=a[i-1][j] && s[2*i-1][j]=='N')
						balance++;
					else
						balance--;
				}
				if (balance < 0){
					for (int j=0; j<m; j++)
						a[i][j] = 3 - a[i][j];
				}
			}
		}
	}
	else{
		for (int j=0; j<m; j++){
			int f = 1;
			for (int i=0; i<n; i++){
				a[i][j] = f;
				if (i!=n-1 && s[2*i+1][j]=='N')
					f = 3-f;
			}
			if (j!=0){
				int balance = 0;
				for (int i=0; i<n; i++){
					if (a[i][j]==a[i][j-1] && s[2*i][j-1]=='E')
						balance++;
					else if (a[i][j]!=a[i][j-1] && s[2*i][j-1]=='N')
						balance++;
					else
						balance--;
				}
				if (balance < 0){
					for (int i=0; i<n; i++)
						a[i][j] = 3 - a[i][j];
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}