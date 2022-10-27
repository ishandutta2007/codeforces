#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5+5;
string s;
int n;
string ans;
vector<int> nxt(MAXN,-1), pre(MAXN, -1);
 
bool valid(int i){
	bool x1 =  (i>=0 && i < n && nxt[i]>=0 && nxt[i] < n && s[i] == '1' && s[nxt[i]] == '0');
	return x1;
}
 
signed main(){
	cin >> s; n = s.length();
	for(int i=0; i< n; ++i) nxt[i] = i+1, pre[i] = i-1;
	queue<int> q;
	for(int i=0; i< n; ++i){
 		if(valid(i)){
			q.push(i);
		}
	}
	ans.assign(n, '*');
	while(!q.empty()){
		int u = q.front(); q.pop();
		int x= pre[u];
		int y = nxt[nxt[u]];
		int t = nxt[u];
		nxt[u] = pre[u] = -1;
		nxt[t] = pre[t] = -1;
		ans[u] = '1'; ans[t] = '0';
		if(x>=0 && x< n)nxt[x] = y;
		if(y>=0 && y< n)pre[y] = x;
		if(valid(x)) q.push(x);
	}
	for(int i=0; i< n; ++i){
		if(ans[i] == '*') ans[i]= '0';
	}
		
	cout << ans;
}