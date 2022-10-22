#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18
#define mod 998244353
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
string s;
int R[2000005];

void manacher(string &s, int R[])
{
	int j = 0, k;
	for(int i = 0; i < (int)s.size();){
		for(; i-j >= 0 && i+j < (int)s.size() && s[i-j] == s[i+j]; j++);
		R[i] = j, k = 1;
		for(; i-k >= 0 && i+k < (int)s.size() && k+R[i-k] < R[i]; k++) R[i+k] = R[i-k];
		j = R[i]-k, i += k;
	}
}

string calc(string &s)
{
	string t;
	for(int i = 0; i < s.size(); i++){
		t += "#";
		t += s[i];
	}
	t += "#";
	
	llint n = t.size();
	manacher(t, R);
	
	llint ans = 0; llint p = -1;
	for(int i = 0; i < n; i++){
		if(i-R[i] < 0 || i+R[i] >= n){
			if(ans < R[i]-1){
				p = i;
				ans = R[i]-1;
			}
		}
	}
	
	string ret;
	for(int i = p-R[p]+1; i <= p+R[p]-1; i++){
		if(t[i] != '#') ret += t[i];
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint n = s.size();
		
		llint eq = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != s[n-1-i]) break;
			eq++;
		}
		if(eq >= n){
			cout << s << endl;
			continue;
		}
		
		string u = s.substr(eq, (llint)s.size()-2*eq);
		string ans = s.substr(0, eq) + calc(u) + s.substr((llint)s.size()-eq);
		cout << ans << "\n";
		
	}
	flush(cout);
	
	return 0;
}