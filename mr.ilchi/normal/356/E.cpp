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
typedef pair<LL,int> pli;

const int MAXN = 100000+10;

bool mark[MAXN][30];
int n;
string s;
int cnt[MAXN][30];
int func[MAXN][30];
LL bad[MAXN];
LL value[MAXN][30];
pli test[MAXN];

inline void suffixArray(){
	for (int i=0; i<n; i++)
		func[i][0] = s[i]-'a'+1;
	for (int i=1; i<=20; i++){
		for (int j=0; j<n; j++){
			if (j + (1<<(i-1)) < n)
				test[j] = pli(func[j][i-1] * (n+1LL) + func[j+(1<<(i-1))][i-1], j);
			else
				test[j] = pli(func[j][i-1] * (n+1LL), j);
		}
		sort(test, test+n);
		int cur = 0;
		for (int j=0; j<n; j++){
			if ((j==0) || (test[j].first != test[j-1].first))
				cur++;
			func[test[j].second][i] = cur;
		}	
	}
}

inline int lcp (int x, int y){
	int ret = 0;
	for (int i=20; i>=0; i--) if (max(x,y)+(1<<i)<=n && func[x][i]==func[y][i])
		x+=(1<<i), y+=(1<<i), ret+=(1<<i);
	return ret;
}

int getCount (int lo, int hi, char x){
	if (lo==0)
		return cnt[hi][x-'a'];
	return cnt[hi][x-'a'] - cnt[lo-1][x-'a'];
}

int main(){
	cin >> s;
	n = (int)s.size();
	int counttemp[30];
	memset(counttemp, 0, sizeof counttemp);
	for (int i=0; i<(int)s.size(); i++){
		counttemp[s[i]-'a']++;
		for (int j=0; j<26; j++)
			cnt[i][j] = counttemp[j];
	}
	suffixArray();
	for (int i=0; i<=n; i++)
		mark[i][0] = true;
	for (int plen=1; plen<=20; plen++){
		int len = (1<<plen)-1;
		for (int i=0; i+len<=n; i++){
			if (getCount(i, i+len-1, s[i+len/2]) == 1){
				if (plen==1){
					mark[i][plen] = true;
					bad[i]++;
					bad[i+1]--;
				}else{
					int temp = lcp(i, i+len/2+1);
					if (temp>=len/2){
						if (mark[i][plen-1]){
							mark[i][plen] = true;
							bad[i]+= (LL)len * len;
							bad[i+len]-= (LL)len * len;
						}
					}else{
						int temp2 = lcp(i+temp+1, i+len/2+1+temp+1);
						if (temp + temp2>= len/2-1){
							if (mark[i][plen-1])
								value[i+len/2+1+temp][s[i+temp]-'a']+= (LL)len * len; 
							if (mark[i+len/2+1][plen-1])
								value[i+temp][s[i+len/2+1+temp]-'a']+= (LL)len * len;
						}
					}
				}
			}else if (getCount(i, i+len-1, s[i+len/2]) == 2){
				int temp = lcp(i, i+len/2+1);
				if (temp < len/2){
					int temp2 = lcp(i+temp+1, i+len/2+1+temp+1);
					if (temp+temp2 >= len/2-1){
						int x = i+temp;
						int y = i+len/2+1+temp;
						if (mark[i][plen-1] && s[y]==s[i+len/2])
							value[y][s[x]-'a']+= (LL)len * len;
						if (mark[i+len/2+1][plen-1] && s[x]==s[i+len/2])
							value[x][s[y]-'a']+= (LL)len * len;
					}
				}
			}
		}
	}
	for (int i=1; i<n; i++)
		bad[i]+= bad[i-1];
	for (int i=0; i<n; i++){
		for (int j=0; j<26; j++)
			value[i][j]++;
		for (int plen=2; plen<=20; plen++){
			int len = (1<<plen)-1;
			if (i-len/2 < 0 || i+len/2 >= n) continue;
			int x = i-len/2;
			if (mark[x][plen-1] && mark[i+1][plen-1] && lcp(x,i+1)>=len/2){
				for (char j='a'; j<='z'; j++) if (getCount(i-len/2,i+len/2,j) == 0)
					value[i][j-'a']+= (LL)len * len;
			}
		}
	}
	LL tot = 0;
	for (int i=0; i<n; i++)
		for (int plen=1; plen<=20; plen++) if (mark[i][plen]){
			int len = (1<<plen)-1;
			tot+= (LL)len * len;
		}
	LL ret = tot;
	for (int i=0; i<n; i++)
		for (char j='a'; j<='z'; j++) if (s[i]!=j){
			ret = max(ret, tot - bad[i] + value[i][j-'a']);
		}
	cout << ret << endl;
	return 0;
}