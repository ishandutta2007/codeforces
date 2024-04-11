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

const int MAXN = 100000+10;

string s;
int sum[MAXN],dp[MAXN];
int match[MAXN];

struct node{
	int pos;
	char type;
	int balance;
	node () {}
	node (int pos, char type, int balance) : pos(pos), type(type), balance(balance) {}
}Q[MAXN];

int main(){
	memset(match,-1,sizeof match);
	cin >> s;
	int len = 0;
	for (int i=0; i<(int)s.size(); i++){
		if (s[i]=='(')
			Q[len++] = node(i,'(',0);
		else if (s[i]=='[')
			Q[len++] = node(i,'[',0);
		else if (len==0)
			continue;
		else if (s[i]==')'){
			if (Q[len-1].type=='('){
				match[Q[len-1].pos] = i;
				len--;
			}
			else if (Q[len-1].balance)
				Q[len-1].balance--;
			else
				len=0;
		}
		else if (s[i]==']'){
			if (Q[len-1].type=='['){
				match[Q[len-1].pos] = i;
				len--;
			}
			else if (Q[len-1].balance)
				Q[len-1].balance--;
			else
				len=0;
		}
		sum[i]= sum[i-1] + (s[i]=='[');
	}
	dp[(int)s.size()] = (int)s.size()-1;
	for (int i=(int)s.size()-1; i>=0; i--){
		if (match[i]==-1)
			dp[i] = i-1;
		else
			dp[i] = dp[match[i]+1];
	}
	int ans = 0, pos = 0;
	for (int i=0; i<(int)s.size(); i++) if (match[i]!=-1){
		int cur = sum[dp[i]];
		if (i!=0)
			cur-=sum[i-1];
		if (cur>ans){
			ans = cur;
			pos = i;
		}
	}
	cout << ans << endl;
	cout << s.substr(pos,dp[pos]-pos+1) << endl;
	return 0;
}