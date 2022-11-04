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

char ans[3000];
string s;
int L;
int cnt[100];
int dp[3000][3000];

inline void go (int lo, int len){
	if (len == 0)	
		return;
	if (len==1){
		ans[L++] = s[lo];
		return;
	}
	int hi = lo + len-1;
	if (s[lo] == s[hi]){
		ans[L++] = s[lo];
		go(lo+1,len-2);
		ans[L++] = s[hi];
		return;
	}
	if (dp[lo][len] == dp[lo][len-1])
		go(lo,len-1);
	else
		go(lo+1,len-1);
}

int main(){
	cin >> s;
	for (int i=0; i<(int)s.size(); i++)
		cnt[s[i]-'a']++;
	for (int i=0; i<26; i++) if (cnt[i]>=100){
		for (int j=0; j<100; j++)
			cout << char('a' + i);
		cout << endl;
		return 0;
	}
	int n = (int)s.size();
	for (int len=1; len<=n; len++){
		for (int i=0; i+len<=n; i++){
			int j = i+len-1;
			if (len == 1){
				dp[i][len] = 1;
				continue;
			}
			if (s[i] == s[j])
				dp[i][len] = dp[i+1][len-2] + 2;
			else
				dp[i][len] = max(dp[i][len-1], dp[i+1][len-1]);
		}
	}
	go(0, n);
	if (L<=100){
		for (int i=0; i<L; i++)
			cout << ans[i];
		cout << endl;
		return 0;
	}
	string ret = "";
	if (L%2 == 0){
		for (int i=(L/2)-50; i<(L/2)+50; i++)
			ret+= ans[i];
	}else{
		for (int i=(L/2)-50; i<=(L/2)+50; i++) if (i!=(L/2))
			ret+= ans[i];
	}
	cout << ret << endl;
	return 0;
}