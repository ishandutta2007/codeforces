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

int n,m;
int Q[MAXN];
int mat[MAXN][MAXN],func[MAXN][MAXN];

bool go (int x){
	memset(func,0,sizeof func);
	for (int j=0; j<m; j++){
		int len = 0;
		for (int i=0; i<n; i++) if (mat[i][j] >= x)
			Q[len++] = i;
		for (int ii=0; ii<len; ii++)
			for (int jj=ii+1; jj<len; jj++){
				func[Q[ii]][Q[jj]]++;
				if (func[Q[ii]][Q[jj]] >= 2)
					return true;
			}
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			scanf("%d", &mat[i][j]);
	int lo=0, hi=1000000000,ans=0;
	while (lo<=hi){
		int mid = (lo + hi) / 2;
		if (go(mid))
			lo=mid+1,ans=mid;
		else
			hi=mid-1;
	}
	printf("%d\n", ans);
	return 0;
}