#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> G[N];
int p[N];
bool cut[N];
int f[30];

int dp[N];

void dfs(int n, int par) {
	p[n] = par;
	for(auto it: G[n])
		if(it != par)
			dfs(it,n);
}

int size(int n, vector<int> &v) {
	int cur = 1;
	for(auto it: G[n])
		if(it != p[n] && !cut[it])
			cur += size(it,v);
	dp[n] = cur;
	v.push_back(n);
	return cur;
}

bool recur(int n, int r) {
	if(r <= 1)
		return true;
	//Find subtree with size
	vector<int> v;
	size(n,v);
	for(auto it: v) {
		if(dp[it] == f[r-2]) {
			cut[it] = true;
			return recur(n,r-1)&recur(it,r-2);
		}
		else if(dp[it] == f[r-1]) {
            cut[it] = true;
			return recur(n,r-2)&recur(it,r-1);
		}
	}
	return false;
}

int main() {
	// your code goes here
	int n; cin>>n;
	for(int i=0;i<n-1;i++) {
		int a,b; cin>>a>>b; a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,0);
	f[0] = 1, f[1] = 2;
	for(int i=2;i<30;i++)
		f[i] = f[i-1]+f[i-2];
    bool fuckyouproblemsetter = true;
	for(int i=0;i<30;i++) {
		if(n == f[i]) {
            fuckyouproblemsetter = false;
            if(recur(0,i))
                cout<<"YES";
            else
                cout<<"NO";
		}
	}
	if(fuckyouproblemsetter)
        cout<<"NO";
	return 0;
}