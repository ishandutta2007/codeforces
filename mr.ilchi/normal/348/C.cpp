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

const int base = 300;
const int MAXN = 100000+10;

bool mlarge[MAXN];
int n,m,q;
int len[MAXN],perm[MAXN];
int inter[MAXN][MAXN/base+10];
LL b[MAXN],a[MAXN],func[MAXN],add[MAXN];
vector <int> large;
vector <int> Q[MAXN],place[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++){
		cin >> len[i];
		for (int j=0; j<len[i]; j++){
			int temp; cin >> temp;
			temp--;
			place[temp].push_back(i);
			Q[i].push_back(temp);
			func[i]+= a[temp];
		}
		if (len[i]>base){
			perm[i] = (int)large.size();
			large.push_back(i);
			mlarge[i] = true;
		}
	}
	for (int i=0; i<n; i++){
		vector <int> big;
		for (int j=0; j<(int)place[i].size(); j++) if (mlarge[place[i][j]])
			big.push_back(place[i][j]);
		for (int j=0; j<(int)place[i].size(); j++)
			for (int k=0; k<(int)big.size(); k++)
				inter[place[i][j]][perm[big[k]]]++;
	}
	for (int o=0; o<q; o++){
		char ord; cin >> ord;
		int pos; cin >> pos; pos--;
		if (ord == '?'){
			if (mlarge[pos]){
				cout << func[pos] << endl;
			}else{
				LL temp = 0;
				for (int j=0; j<(int)Q[pos].size(); j++)
					temp+= b[Q[pos][j]];
				for (int j=0; j<(int)large.size(); j++)
					temp+= (LL)inter[pos][j] * add[large[j]];
				cout << func[pos] + temp << endl;
			}
		}else{
			int val; cin >> val;
			add[pos]+= val;
			if (mlarge[pos]){	
				for (int i=0; i<(int)large.size(); i++)
					func[large[i]]+= (LL)inter[pos][i] * val;
			}else{
				for (int i=0; i<(int)Q[pos].size(); i++)
					b[Q[pos][i]]+= val;
				for (int i=0; i<(int)large.size(); i++)
					func[large[i]]+= inter[pos][i] * val;
			}
		}
	}
	return 0;
}