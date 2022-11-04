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

int cnt[200000][3];

int main(){
	string s; cin >> s;
	int n = (int)s.size();
	int cx=0,cy=0,cz=0;
	for (int i=0; i<n; i++){
		if (s[i]=='x') cx++;
		if (s[i]=='y') cy++;
		if (s[i]=='z') cz++;
		cnt[i][0]=cx, cnt[i][1]=cy, cnt[i][2]=cz;
	}	
	int m; cin >> m;
	for (int i=0; i<m; i++){
		int lo,hi; cin >> lo >> hi;
		lo--; hi--;
		int fx = cnt[hi][0], fy = cnt[hi][1], fz = cnt[hi][2];
		if (lo != 0)
			fx-= cnt[lo-1][0], fy-= cnt[lo-1][1], fz-= cnt[lo-1][2];
		if ((abs(fx-fy)<=1 && abs(fx-fz)<=1 && abs(fy-fz)<=1) || (hi-lo<=1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}