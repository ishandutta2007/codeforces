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
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const int maxL = 100 * 1000 + 10;

int t;
int pre[maxL],suf[maxL],nex[maxL];
string s;

void kmp (string now , int *dp){

	int match=0;
	nex[0]=0;
	for (int i=1; i<(int)now.size(); i++){
		while (now[i]!=now[match] && match!=0)
			match = nex[match-1];
		if (now[i]==now[match])
			match++;
		nex[i]=match;
	}

	match = 0;
	for (int i=0; i<(int)s.size(); i++){
		while (s[i]!=now[match] && match!=0)
			match = nex[match-1];
		if (s[i]==now[match])
			match++;
		dp[i] = match;
		if (match == (int)now.size())
			match = nex[match-1];
	}	
}

int main(){
	
	cin >> s >> t;

	int ans = 0;

	for (int o=1; o<=t; o++){
		
		string ss; cin >> ss;

		if (ss.size()==1) continue;
		
		kmp(ss,pre); reverse(ss.begin(),ss.end()); reverse(s.begin(),s.end());
		kmp(ss,suf); reverse(ss.begin(),ss.end()); reverse(s.begin(),s.end()); reverse(suf,suf+(int)s.size());

	//	for (int i=0; i<(int)s.size(); i++) 
	//		cout << pre[i] << ' ' << suf[i] << endl;

		int prefix = 0;

		for (int i=0; i<(int)s.size(); i++){
			if (suf[i] + prefix >= (int)ss.size()){
				ans++; break;
			}
			prefix = max (prefix , pre[i]);
		}
	}

	cout << ans << endl;

	return 0;
}