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

int n,que;
int p[MAXN],a[MAXN],b[MAXN];
double test[MAXN];
double func[MAXN][MAXN];

int main(){
	cin >> n >> que;
	for (int i=0; i<n; i++)
		cin >> p[i];
	for (int i=0; i<que; i++){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			func[i][j] = 1.0;
	for (int i=que-1; i>=0; i--){
		for (int k=0; k<n; k++) if (k!=a[i] && k!=b[i])
			test[k] = (func[k][a[i]]+func[k][b[i]])/2.0;
		for (int k=0; k<n; k++) if (k!=a[i] && k!=b[i]){
			func[k][a[i]] = func[k][b[i]] = test[k];
			func[a[i]][k] = func[b[i]][k] = 1.0-test[k];
		}
		func[a[i]][b[i]] = func[b[i]][a[i]] = 0.5;
	}
	double ans = 0.0;
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) if (p[i]>p[j])
			ans+= func[i][j];
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}