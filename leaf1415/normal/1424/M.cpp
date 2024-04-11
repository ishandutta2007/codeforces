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
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define rep2(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define pback push_back
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, k;
vector<string> tmp[1005];
vector<string> vec;
vector<llint> G[26];
vector<int> topo;
bool used[10005];
bool valid[26];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint p; string s;
	rep(i, 1, n){
		cin >> p;
		rep(j, 1, k){
			cin >> s;
			tmp[p].pback(s);
		}
	}
	rep(i, 0, n){
		for(auto x: tmp[i]){
			vec.pback(x);
		}
	}
	
	for(auto s: vec){
		for(auto c : s){
			valid[c-'a'] = true;
		}
	}
	
	rep2(i, 1, (int)vec.size()){
		string s = vec[i-1], t = vec[i];
		bool flag = false;
		rep2(j, 0, min(s.size(), t.size())){
			if(s[j] != t[j]){
				G[s[j]-'a'].pback(t[j]-'a');
				flag = true;
				break;
			}
		}
		if(!flag){
			if(s.size() > t.size()){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	
	for(int i = 0; i < 26; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	for(int i = 0; i < 26; i++) used[i] = false;
	for(auto x : topo){
		used[x] = true;
		for(auto v : G[x]){
			if(used[v]){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	
	for(auto x: topo) if(valid[x]) cout << (char)(x+'a'); cout << endl;
	
	return 0;
}