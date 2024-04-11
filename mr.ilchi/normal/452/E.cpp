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

const int mod = 1000000007;

int P,n[3];
int sum[3][1<<20];
string s[3];
pair<int,int> perm[1<<20];
long long dp[3][300010][20]; 
vector <int> Q[1<<20];

inline bool cmp (const pair<int,int> &A, const pair<int,int> &B){
	return dp[A.first][A.second][P] < dp[B.first][B.second][P];
}

inline int lcp (pair<int,int> A, const pair<int,int> B){
	int ret = 0;
	int x = A.second, y = B.second;
	for (int i = P; i>=0; i--) if (x + (1<<i) <= n[A.first] && y + (1<<i) <= n[B.first]){ 
		if (dp[A.first][x][i] == dp[B.first][y][i]){
			ret+= (1<<i);
			x+= (1<<i);
			y+= (1<<i);
		}
	}
	return ret;
}

void suffix(){
	for (int i=0; i<3; i++)
		for (int j=0; j<s[i].size(); j++)
			dp[i][j][0] = s[i][j];
	for (int i=0; i<n[0]+n[1]+n[2]; i++){
		if (i<n[0])
			perm[i] = make_pair(0, i);
		else if (i < n[0] + n[1])
			perm[i] = make_pair(1, i - n[0]);
		else
			perm[i] = make_pair(2, i - n[0] - n[1]);
	}
	for (P = 1; (1<<(P-1)) <= min(s[0].size(), min(s[1].size(), s[2].size())); P++){
		for (int i=0; i<3; i++){
			for (int j=0; j<s[i].size(); j++){
				if (j + (1<<(P-1)) < n[i])
					dp[i][j][P] = dp[i][j][P-1] * 1000000LL + dp[i][j + (1<<(P-1))][P-1];
				else
					dp[i][j][P] = dp[i][j][P-1] * 1000000LL;
			}
		}
		sort(perm, perm + n[0] + n[1] + n[2], cmp);
		int cur = 1;
		for (int i=0; i<n[0]+n[1]+n[2]; i++){
			int j = i;
			long long last = dp[perm[i].first][perm[i].second][P];
			while (j < n[0]+n[1]+n[2] && dp[perm[j].first][perm[j].second][P] == last){
				dp[perm[j].first][perm[j].second][P] = cur;
				j++;
			}
			cur++; 
			i = j-1;
		}
	}
	P--;
}

long long get (int lo, int hi){
	int s0 = sum[0][hi+1] - sum[0][lo];
	int s1 = sum[1][hi+1] - sum[1][lo];
	int s2 = sum[2][hi+1] - sum[2][lo];
	return (long long)s0 * (long long)s1 * s2;
}

int main(){
	cin >> s[0] >> s[1] >> s[2];
	n[0] = s[0].size(), n[1] = s[1].size(), n[2] = s[2].size();
	suffix();
	int tot = n[0] + n[1] + n[2];
	for (int i=0; i<tot; i++){
		sum[0][i+1] = sum[0][i] + (perm[i].first == 0);
		sum[1][i+1] = sum[1][i] + (perm[i].first == 1);
		sum[2][i+1] = sum[2][i] + (perm[i].first == 2);
	}
	for (int i=0; i<tot-1; i++){
		Q[lcp(perm[i], perm[i+1]) + 1].push_back(i);	
	}
	long long sum = (long long)n[0] * (long long)n[1] * n[2];
	set < pair<int,int> > SET;
	SET.insert(make_pair(0, tot-1));
	for (int len = 1; len <= min(n[0], min(n[1], n[2])); len++){
		for (int i=0; i<Q[len].size(); i++){
			set < pair<int,int> > :: iterator it = SET.upper_bound(make_pair(Q[len][i]+1, -1)); it--;
			pair<int,int> range = *it; SET.erase(it);
			sum-= get(range.first, range.second);
			sum+= get(range.first, Q[len][i]);
			sum+= get(Q[len][i]+1, range.second);
			SET.insert(make_pair(range.first, Q[len][i]));
			SET.insert(make_pair(Q[len][i]+1, range.second));
		}
		if (len != 1)
			cout << ' ';
		cout << sum % mod;
	}
	cout << endl;
	return 0;
}