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

bool mark[200][2];
int n,que;
int dp[200][2][2][2][2];

//0 not mark
//1 have mark

inline int go(int len, int f0, int f1, int c0, int c1){
	if (len<=0)
		return 0;
	int &ret = dp[len][f0][f1][c0][c1];
	if (ret != -1)
		return ret;
	if (len == 1)
		return ret = (f0==0 || f1==0) ? (1) : (0);
	vector <int> Q;
	for (int i=0; i<len; i++){
		if (i==0){
			if (f0 == 0){
				if (len == 2)
					Q.push_back(1-c0);
				else
					Q.push_back(go(len-1, 0, 1, c0, c1));
			}
			if (f1 == 0){
				if (len == 2)
					Q.push_back(1-c1);
				else
					Q.push_back(go(len-1, 1, 0, c0, c1));
			}
		}else if (i==len-1){
			if (c0 == 0){
				if (len == 2)
					Q.push_back(1-f0);
				else
					Q.push_back(go(len-1, f0, f1, 0, 1));
			}
			if (c1 == 0){
				if (len == 2)
					Q.push_back(1-f1);
				else
					Q.push_back(go(len-1, f0, f1, 1, 0));
			}
		}else{
			int t0 = go(i, f0, f1 || (i==1), 0, 1);
			if (i==len-2) 
				t0^= (1-c0); 
			else
				t0^= go(len-i-1, 0, 1, c0, c1);
			int t1 = go(i, f0 || (i==1), f1, 1, 0); 
			if (i==len-2)
				t1^= (1-c1);
			else
				t1^= go(len-i-1, 1, 0, c0, c1);
			Q.push_back(t0);
			Q.push_back(t1);
		}		
	}
	sort(Q.begin(),Q.end());
	Q.resize(unique(Q.begin(),Q.end())-Q.begin());
	for (int i=0; i<(int)Q.size(); i++) if (Q[i] != i)
		return ret = i;
	return ret = (int)Q.size();
}

int main(){
	cin >> n >> que;
	for (int i=0; i<que; i++){
		int x,y;
		cin >> x >> y;
		x--; y--;
		mark[x][y] = true;
		mark[x][1-y] = true;
		if (x!=0) mark[x-1][1-y] = true;
		if (x!=n-1) mark[x+1][1-y] = true;
	}
	memset(dp, -1, sizeof dp);
	int ret = 0;
	int last = -1;
	for (int i=0; i<n; i++){
		if (mark[i][0] && mark[i][1]){
			if (i-1 != last)
				ret^= go(i-last-1, mark[last+1][0], mark[last+1][1], mark[i-1][0], mark[i-1][1]);	
			last = i;
		}
	}
	if (last!=n-1)
		ret^= go(n-last-1, mark[last+1][0], mark[last+1][1], mark[n-1][0], mark[n-1][1]);
	cout << ((ret) ? ("WIN") : ("LOSE")) << endl;
	return 0;
}