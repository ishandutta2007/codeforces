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

const int maxN = 700 + 10;
const int mod  = 1000 * 1000 * 1000 + 7;

int match[maxN];
int dp[maxN][maxN][3][3];	
string s;

int go (int b, int f, int bc, int fc){
	
	if (f<b) 
		return 1;

	if (dp[b][f][bc][fc]!=-1)
		return dp[b][f][bc][fc];
	
	int ret = 0;
	for (int i=1; i<=2; i++){
		int p = match[b];
		if (f==p){
			if (i!=bc) ret= (ret+go(b+1,f-1,i,0))%mod;
			if (i!=fc) ret= (ret+go(b+1,f-1,0,i))%mod;
		}
		else{
			if (i!=bc) ret= (ret+(ll)go(b+1,p-1,i,0)*go(p+1,f,0,fc))%mod;
			ret= (ret+(ll)go(b+1,p-1,0,i)*go(p+1,f,i,fc))%mod;
		}
	}

	return dp[b][f][bc][fc] = ret;
}

int main(){
	
	cin >> s;
	
	stack <int> st;

	for (int i=0; i<(int)s.size(); i++){
		if (s[i]=='(')
			st.push(i);
		else{
			match[i] = st.top();
			match[st.top()] = i;
			st.pop();
		}
	}

	memset(dp,-1,sizeof dp);

	cout << go(0,(int)s.size()-1,0,0) << endl;

	return 0;
}