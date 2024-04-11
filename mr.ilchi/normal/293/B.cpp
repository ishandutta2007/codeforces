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

const int mod = 1000000007;

int n,m,k;
int last[12],pos[12],p[12];
int mat[12][12], test[12][12];
int dp[30][36*36*36*36+10];
vector <int> store;

int go (int index, int mask){
	if (index == n * m - 1)
		return 1;
	int &ret = dp[index][mask];
	if (ret != -1)
		return ret;
	int x = index/m;
	int y = index%m;
	ret = 0;
	if (mat[x][y]!=0){
		if (last[mat[x][y]] <= y)
			return ret;
		int temp = last[mat[x][y]];
		last[mat[x][y]] = y;
		ret = go(index+1, mask - ((index==0 || index==n*m-1) ? (0) : (p[pos[mat[x][y]]] * (y-temp))));
		last[mat[x][y]] = temp;
		return ret;
	}	
	for (int i=0; i<(int)store.size(); i++) if (y < last[store[i]]){
		int temp = last[store[i]];
		last[store[i]] = y;
		ret = (ret + go(index+1, mask - p[pos[store[i]]] * (y-temp))); 
		if (ret>=mod) ret-=mod;
		last[store[i]] = temp;
	}
	return ret;
}

inline int put (int x, int y){
	if (mat[x][y]!=0)
		return 1;
	vector <bool> mark(k+1, false);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			mark[mat[i][j]] = true;
	int ret = 0;
	for (int i=1; i<=k; i++) if (mark[i]==false){
		ret++;
		mat[x][y] = i;
	}
	return ret;
}

int main(){
	cin >> n >> m >> k;
	if (k < n + m - 1){
		cout << 0 << endl;
		return 0;
	}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> mat[i][j];
	if (n<m){
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				test[j][i] = mat[i][j];
		swap(n,m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				mat[i][j] = test[i][j];
	}
	int comb = 1;
	comb = comb * put(0,0);
	comb = comb * put(n-1,m-1);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (mat[i][j]!=0)
			for (int ii=i; ii<n; ii++)
				for (int jj=j; jj<m; jj++) if ((ii!=i || jj!=j) && (mat[i][j]==mat[ii][jj]))
					comb = 0;
	if (comb == 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i=1; i<=k; i++) if (mat[0][0]!=i && mat[n-1][m-1]!=i){
		store.push_back(i);
		pos[i] = (int)store.size()-1;
	}
	p[0] = 1;
	for (int i=1; i<=k; i++)
		p[i] = p[i-1] * (m+1);
	for (int i=1; i<=k; i++) 
		last[i] = m;
	memset(dp, -1, sizeof dp);
	cout << ((LL)comb * go(0, p[(int)store.size()]-1)) % mod << endl;
	return 0;
}