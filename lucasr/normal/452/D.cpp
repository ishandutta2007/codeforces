#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define MAXT 10011000

int have[MAXT][3];
int t[3], k, cur[3];

int main() {
	memset(have, 0, sizeof(have));
	cin>>k>>have[0][0]>>have[0][1]>>have[0][2]>>t[0]>>t[1]>>t[2];
	cur[0] = have[0][0];
	cur[1] = have[0][1];
	cur[2] = have[0][2];
	int curpos = 0;
	while (k > 0) {
		while (k > 0 && cur[0] > 0 && cur[1] > 0 && cur[2] > 0) {
			cur[0]--; cur[1]--; cur[2]--; k--;
			have[curpos+t[0]][0]++;
			have[curpos+t[1]][1]++;
			have[curpos+t[2]][2]++;
		}
		if (k==0) break;
		curpos++;
		for (int i=0;i<3;i++) cur[i]+=have[curpos][i];
	}
	
	cout<<curpos + t[0] + t[1] + t[2]<<endl;
	return 0;
}