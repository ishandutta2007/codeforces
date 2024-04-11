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

const int MAXN = 1000+10;

int n,m,q;
int t0[MAXN],t1[MAXN],L[MAXN],R[MAXN];
int a[MAXN][MAXN];
int lef[MAXN][MAXN],rig[MAXN][MAXN],up[MAXN][MAXN],bot[MAXN][MAXN];

void set_row (int r){
	lef[r][0] = (a[r][0] == 1);
	for (int j=1; j<m; j++) 
		lef[r][j] = (a[r][j] == 0) ? (0) : (1 + lef[r][j-1]);
	rig[r][m-1] = (a[r][m-1] == 1);
	for (int j=m-2; j>=0; j--)
		rig[r][j] = (a[r][j] == 0) ? (0) : (1 + rig[r][j+1]);
}

void set_col (int c){
	up[0][c] = (a[0][c] == 1);
	for (int i=1; i<n; i++)
		up[i][c] = (a[i][c] == 0) ? (0) : (1 + up[i-1][c]);
	bot[n-1][c] = (a[n-1][c] == 1);
	for (int i=n-2; i>=0; i--)
		bot[i][c] = (a[i][c] == 0) ? (0) : (1 + bot[i+1][c]);
}

int get_max (int len, int* val, int pos){
	stack <int> st;
	for (int i=0; i<len; i++){
		while (!st.empty() && val[st.top()] >= val[i])
			st.pop();
		if (st.empty())
			L[i] = -1;
		else
			L[i] = st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=len-1; i>=0; i--){
		while (!st.empty() && val[st.top()] >= val[i])
			st.pop();
		if (st.empty())
			R[i] = len;
		else
			R[i] = st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	int ans = 0;
	for (int i=0; i<len; i++) 
		if (L[i]<pos && pos<R[i])
			ans = max(ans, (R[i]-L[i]-1) * val[i]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];
	for (int i=0; i<n; i++) 
		set_row(i);
	for (int j=0; j<m; j++) 
		set_col(j);
	for (int o=0; o<q; o++){
		int op,x,y;
		cin >> op >> x >> y;
		x--; y--;
		if (op == 1){
			a[x][y] = 1 - a[x][y];
			set_row(x);
			set_col(y);
		}else{
			for (int i=0; i<n; i++) 
				t0[i] = lef[i][y], t1[i] = rig[i][y];
			cout << max(max(get_max(m, up[x], y), get_max(m, bot[x], y)), max(get_max(n, t0, x), get_max(n, t1, x))) << endl;
		}
	}
	return 0;
}