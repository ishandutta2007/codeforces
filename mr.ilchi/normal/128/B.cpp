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
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int maxN = 100*1000 + 5;
const ll base = 1000*1000;

int k,n;
ll dp[maxN][25];
pli test[maxN];
string s;

inline void sArray (){
	
	for (int i=0; i<n; i++)
		dp[i][0] = s[i];

	for (int i=1; i<=20; i++){
		
		for (int j=0; j<n; j++){
			
			int p = j+(1<<(i-1));

			if (p<n)
				dp[j][i] = dp[j][i-1] * base + dp[p][i-1];
			else
				dp[j][i] = dp[j][i-1] * base;
		}

		for (int j=0; j<n; j++)
			test[j] = pli(dp[j][i],j);

		sort (test , test+n);

		ll past = -1 , now = 0;

		for (int j=0; j<n; j++){
			
			if (test[j].first!=past)
				now++;

			dp[test[j].second][i] = now;

			past = test[j].first;
		}
	}
}

inline bool cmp (const int &x, const int &y){
	
	return (dp[x][20]!=dp[y][20]) ? dp[x][20]<dp[y][20] : y>x;
}

inline int lcp (int a1 , int a2){
	
	int Len = min(n-a1,n-a2);

	if (Len<=0)
		return 0;

	for (int i=20; i>=0; i--) if ((1<<i)<=Len && dp[a1][i]==dp[a2][i])
		return (1<<i) + lcp(a1+(1<<i),a2+(1<<i));

	return 0;
}	

int main(){

	cin >> s >> k;

	n = (int)s.size();

	if ((ll)n * (ll)(n-1) + 2ll*n < 2ll*(ll)k){
		cout << "No such line." << endl;
		return 0;
	}

	sArray();

	vector <int> Q;

	for (int i=0; i<n; i++)
		Q.push_back (i);

	sort (Q.begin(), Q.end(),cmp);

	vector <int> P;

	for (int i=1; i<(int)Q.size(); i++) 
		P.push_back (lcp(Q[i-1],Q[i]));

	for (int i=0; i<(int)Q.size(); i++){
		
		int id = Q[i] , start;

		if (i!=0)
			start = P[i-1] + id;
		else
			start = id;

		while (start<n){
			
			int len = start - id + 1; k--;

			for (int j=i+1; j<(int)Q.size(); j++){ 
				if (P[j-1]<len)
					break;
				else
					k--;
			}

			if (k<=0){
				cout << s.substr(id,len) << endl;
				return 0;
			}

			start++;
		}
	}

	return 0;
}