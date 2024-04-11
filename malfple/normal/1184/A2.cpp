#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const int N = 2e5;

int dsu[N + 5];
string s;
int n;
int find(int x){
	if(dsu[x] == x)return x;
	return dsu[x] = find(dsu[x]);
}

void merge(int a, int b){
	dsu[find(a)] = find(b);
}

bool vis[N + 5];
int val[N + 5];

int dfs(int x, int k){
	if(vis[x])return 0;
	vis[x] = true;
	int res = s[x] == '1';
	return res + dfs((x + k) % n, k);
}

bool check(int k){
	if(val[k] != -1)return val[k];
	memset(vis, 0, sizeof vis);
	int res = 1;
	for(int j = 0; j < n; ++j){
		if(vis[j])continue;
		int cnt = dfs(j, k);
		if(cnt % 2 == 0)continue;
		res = 0;
	}
	return val[k] = res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(val, -1, sizeof val);
	cin >> n;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += check(__gcd(i, n));
	}
	
	cout << ans << endl;
}