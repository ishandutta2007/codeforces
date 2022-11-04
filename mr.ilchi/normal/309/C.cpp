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

int n,m;
int a[1<<20],c[100];

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<m; i++){
		int t; scanf("%d", &t);
		c[t]++;
	}
	sort(a, a+n);
	int ret = 0;
	int start = 0;
	for (int i=0; i<30; i++){
		for (int j=start; j<n && c[i]; j++) if (a[j] & 1){
			a[j]--;
			c[i]--;
			ret++;
		}
		while (start < n){
			if (a[start]<c[i]){
				ret+= a[start];
				c[i]-=a[start];
				start++;
			}else{
				ret+= c[i];
				a[start]-=c[i];
				break;
			}
		}
		for (int j=start; j<n; j++)
			a[j]>>=1;
	}
	cout << ret << endl;
	return 0;
}