#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 220;
string s, t, ans;
int dp[MX][MX][MX], n, m;

int getAns(int i, int j, int d) {
	if(d == MX) return INF;
	if(dp[i][j][d] == -1) {
		if(i == n && j == m) {
			dp[i][j][d] = d;
		} else if(i == n) {
			if(t[j] == '(') dp[i][j][d] = 1+getAns(i,j+1,d+1);
			else if(d != 0) dp[i][j][d] = 1+getAns(i,j+1,d-1);
			else			dp[i][j][d] = 1+getAns(i,j  ,d+1);
		} else if(j == m) {
			if(s[i] == '(') dp[i][j][d] = 1+getAns(i+1,j,d+1);
			else if(d != 0) dp[i][j][d] = 1+getAns(i+1,j,d-1);
			else			dp[i][j][d] = 1+getAns(i  ,j,d+1);
		} else {
			dp[i][j][d] = 1+getAns(i+(s[i]=='('), j+(t[j]=='('), d+1);
			if(d != 0) dp[i][j][d] = min(dp[i][j][d], 1+getAns(i+(s[i]==')'), j+(t[j]==')'), d-1));
		}
	}
	return dp[i][j][d];
}
void fillAns(int i, int j, int d) {
	if(i == n && j == m) {
		RE(k,d) ans.pb(')');
	} else if(i == n) {
		if(t[j] == '(') ans.pb('('), fillAns(i,j+1,d+1);
		else if(d != 0) ans.pb(')'), fillAns(i,j+1,d-1);
		else			ans.pb('('), fillAns(i,j  ,d+1);
	} else if(j == m) {
		if(s[i] == '(') ans.pb('('), fillAns(i+1,j,d+1);
		else if(d != 0) ans.pb(')'), fillAns(i+1,j,d-1);
		else			ans.pb('('), fillAns(i  ,j,d+1);
	} else {
		if(getAns(i,j,d) == 1+getAns(i+(s[i]=='('), j+(t[j]=='('), d+1))
			ans.pb('('), fillAns(i+(s[i]=='('), j+(t[j]=='('), d+1);
		else
			ans.pb(')'), fillAns(i+(s[i]==')'), j+(t[j]==')'), d-1);
	}
}

void program() {
	cin>>s>>t; n=s.size(); m=t.size();
	RE(i,MX) RE(j,MX) RE(k,MX) dp[i][j][k] = -1;
	getAns(0,0,0);
	fillAns(0,0,0);
	cout<<ans<<endl;
}