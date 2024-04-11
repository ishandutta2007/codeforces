/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXQ = 10000+10;
const int MAXN = 1000000+10;

bool mark[1<<26];
int que;
int cost[MAXQ],last[MAXQ],ans[MAXQ],d[30],perm[30];
int nex [MAXN][30];
vector <int> have;

int get (int mask) { return upper_bound(have.begin(),have.end(),mask)-have.begin(); }

bool cmp (const int &A , const int &B){
	return d[A]<d[B];
}

int main(){
	ios_base::sync_with_stdio(false);
	string s; cin >> s;
	cin >> que;
	for (int i=1; i<=que; i++){
		string ss; cin >> ss;
		for (int j=0; j<(int)ss.size(); j++)
			cost[i]+=(1<<(ss[j]-'a'));
		mark[cost[i]] = true;
		have.push_back(cost[i]);
	}
	int len = (int)s.size();
	sort(have.begin(),have.end());
	have.resize(unique(have.begin(),have.end())-have.begin());
	for (int i=0; i<=(int)have.size(); i++)
		last[i] = len;	
	for (int i=0; i<26; i++)
		nex[len][i] = len;
	for (int i=len-1; i>=0; i--){
		for (int j=0; j<26; j++){
			d[j] = nex[i][j] = nex[i+1][j];
			perm[j]=j;
		}
		d[s[i]-'a'] = nex[i][s[i]-'a'] = i;
		sort(perm,perm+26,cmp);
		perm[26] = 26;
		d[26] = len;
		int mask = 0;
		for (int j=0; j<26 && d[perm[j]]<len; j++){
			mask+= (1<<perm[j]);
			if (mark[mask]){
				int tmp = get(mask);
				if (d[perm[j+1]]-1 < last[tmp])
					ans[tmp]++;
				last[tmp] = i;
			}
		}
	}
	for (int i=1; i<=que; i++)
		cout << ans[get(cost[i])] << endl;
	return 0;
}