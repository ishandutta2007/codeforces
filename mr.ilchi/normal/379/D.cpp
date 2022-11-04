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
typedef pair<int,int> pii;
typedef complex<double> point;

const string STR = "BAC";

int n,m,k,x;
int dp[300][300][10];

bool ok (int f0, int f1, int m0, int m1){
	for (int i=3; i<=k; i++){
		int tmp = f0 + f1;
		int mt = (m0%3) + 3 * ((m1/3)%3);
		tmp+= ((m0/3)%3 == 1) && (m1%3 == 2);
		if (tmp > x)
			return false;
		f0 = f1;
		f1 = tmp;
		m0 = m1;
		m1 = mt;
	}
	return f1 == x;
}

int can (int len, int need, int mask){
	if (need < 0)
		return 0;
	if (len == 1){
		if ((mask%3) != ((mask/3)%3))
			return false;
		return need == 0;
	}
	if (len == 2){
		need-= (((mask%3)==1) && (((mask/3)%3)==2));
		return need == 0;
	}
	int &ret = dp[len][need][mask];
	if (ret != -1)
		return ret;
	for (int i=0; i<3; i++){
		int f0 = mask%3;
		int f1 = (mask/3)%3;
		if (can(len-1, need - ((f0==1) && (i==2)), i + f1*3))
			return ret = 1;
	}
	return ret = 0;
}

void build (int len, int need, int mask){
	int f0 = mask%3;
	int f1 = (mask/3)%3;
	if (len == 1){
		cout << STR[f0];
		return;
	}
	if (len == 2){
		cout << STR[f0] << STR[f1];
		return;
	}
	for (int i=0; i<3; i++){
		if (can(len-1, need-((f0==1) && (i==2)), i+f1*3)){
			cout << STR[f0];
			build(len-1, need-((f0==1) && (i==2)), i+f1*3);
			return;
		}
	}
}

int main(){
	cin >> k >> x >> n >> m;
	memset(dp, -1, sizeof dp);
	for (int i=0; i<=n; i++)
		for (int ii=0; ii<9; ii++) if (can(n, i, ii))
			for (int j=0; j<=m; j++)
				for (int jj=0; jj<9; jj++) if (can(m, j, jj)){
					if (ok(i, j, ii, jj)){
						build(n, i, ii); cout << endl;
						build(m, j, jj); cout << endl;
						return 0;
					}
				}
	cout << "Happy new year!" << endl;
	return 0;
}