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

const string color = "RGB";

string s,t;
int lo[1<<20],hi[1<<20];
int cnt[1<<20][3][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	int ns = (int)s.size();
	int nt = (int)t.size();
	int L=0, R=-1;
	for (int i=0; i<nt; i++){
		if (R < ns-1) R++;
		while (R<ns-1 && s[R]!=t[i])
			R++;
		lo[i] = L, hi[i] = R;
		if (L<ns && t[i] == s[L])
			L++;
//		cerr << i << " : " << lo[i] << ' ' << hi[i] << endl;
	}
	cnt[1][color.find(s[0])][0] = 1;
	cnt[1][color.find(s[0])][1] = 1;
	cnt[1][color.find(s[0])][2] = 1;
	for (int i=1; i<ns; i++) if (s[i]!=s[i-1])
		cnt[i+1][color.find(s[i])][color.find(s[i-1])]++;
	for (int i=1; i<=ns; i++)
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
				cnt[i][j][k]+= cnt[i-1][j][k];
	LL ret = hi[0]-lo[0]+1;
	for (int i=1; i<nt; i++) if (lo[i]<=hi[i]){
		ret+= hi[i]-lo[i]+1;
		if (lo[i] <= hi[i-1])
			ret-= cnt[hi[i-1]+1][color.find(t[i-1])][color.find(t[i])] - cnt[lo[i]][color.find(t[i-1])][color.find(t[i])];
	}
	cout << ret << endl;
	return 0;
}