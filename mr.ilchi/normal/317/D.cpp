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

const int MAXT = 100000;

bool mark[MAXT];
int n;
int vis[MAXT];
int nim[100];
map <int, int> mp;

inline int getNim (int len){
	int mask = 0;
	for (int i=1; i<=len; i++) if (vis[i])
		mask|=(1<<(i-1));
	if (mp.find(mask)!=mp.end())
		return mp[mask];
	vector <int> Q;
	for (int i=1; i<=len; i++) if (vis[i]==0){
		for (int j=i; j<=len; j+=i)
			vis[j]++;
		Q.push_back(getNim(len));
		for (int j=i; j<=len; j+=i)
			vis[j]--;
	}
	sort(Q.begin(), Q.end());
	Q.push_back(10000);
	Q.resize(unique(Q.begin(),Q.end())-Q.begin());
	for (int i=0; i<(int)Q.size(); i++) if (Q[i]!=i)
		return mp[mask] = i;
	return -100;
}

int main(){
	
/*	for (int i=1; i<=29; i++){
		cout << "nim[" << i << "] = " << getNim(i) << endl;
		mp.clear();
	}
	return 0;*/
	nim[1] = 1;
	nim[2] = 2;
	nim[3] = 1;
	nim[4] = 4;
	nim[5] = 3;
	nim[6] = 2;
	nim[7] = 1;
	nim[8] = 5;
	nim[9] = 6;
	nim[10] = 2;
	nim[11] = 1;
	nim[12] = 8;
	nim[13] = 7;
	nim[14] = 5;
	nim[15] = 9;
	nim[16] = 8;
	nim[17] = 7;
	nim[18] = 3;
	nim[19] = 4;
	nim[20] = 7;
	nim[21] = 4;
	nim[22] = 2;
	nim[23] = 1;
	nim[24] = 10;
	nim[25] = 9;
	nim[26] = 3;
	nim[27] = 6;
	nim[28] = 11;
	nim[29] = 12;

	cin >> n;
	int ret = 0;
	int tot = n;
	for (int i=2; i*i<=n; i++) if (!mark[i]){
		LL temp = i;
		int cnt = 0;
		while (temp <= n){
			cnt++;
			if (temp<MAXT)
				mark[temp] = true;
			temp = temp * i;
		}
		tot-=cnt;
		ret = ret ^ nim[cnt];
	}
	if (tot%2)
		ret^=1;
	cout << ((ret) ? ("Vasya") : ("Petya")) << endl;
	return 0;
}