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

const int MAXL = 1000000+10;

int n;
int cnt[MAXL],dp[MAXL],Count[MAXL][5];
LL a[MAXL];

int getF1(LL x){
	int s = 1, e = 1000000, ret=1;
	while (s<=e){
		int mid = (s+e) / 2;
		if ((LL)mid * mid <= x){
			ret = mid;
			s = mid+1;
		}
		else
			e = mid-1;
	}
	return ret;
}

int getF2(LL x){
	int s = 1, e = 10000, ret=1;
	while (s<=e){
		int mid = (s+e) / 2;
		if ((LL)mid * mid * mid * mid >= x){
			ret = mid;
			e = mid-1;
		}
		else
			s = mid+1;
	}
	return ret;
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int f1 = 2;
	int f2 = 3;
	dp[4] = 1;
	cnt[0] = 1;
	int cur = 1;
	for (int i=5; i<MAXL; i++){
		while (f1 * f1 * f1 * f1 < i){
			cnt[dp[f1]]--;
			if (cnt[dp[f1]]==0 && cur>dp[f1])
				cur = dp[f1];
			f1++;
		}
		while (f2 * f2 <= i){
			cnt[dp[f2]]++;
			while (cnt[cur]) 
				cur++;
			f2++;
		}
		dp[i] = cur;
	}
	for (int i=0; i<MAXL; i++){
		for (int j=0; j<=3; j++)
			Count[i][j] = Count[max(i-1,0)][j];
		Count[i][dp[i]]++;
	}
	int val = 0;
	for (int i=0; i<n; i++){
		int f1 = getF1(a[i]);
		int f2 = getF2(a[i]);
		swap(f1,f2);
		if (a[i]<MAXL){
			val = val ^ dp[a[i]];
		}
		else{
			bool f = false;
			for (int j=0; j<=3; j++) if ((Count[f2][j] - Count[f1-1][j]) == 0){
				f = true;
				val = val ^ j;
				break;
			}
			if (!f)
				val^=4;
		}
	}
	if (val)
		cout << "Furlo" << endl;
	else
		cout << "Rublo" << endl;
	return 0;
}