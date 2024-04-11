#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

int n, m;
vector<llint> vec;
map<string, int> mp;
llint G[45];
vector<P> vec2;
llint table[1<<20];

void dfs(llint used, llint nx, llint sum)
{
	if(nx == m/2){
		vec2.push_back(make_pair(used, sum));
		return;
	}
	if((used & (1LL<<nx)) == 0) dfs(used|G[nx], nx+1, sum+1);
	dfs(used, nx+1, sum);
}

void dfs2(llint used, llint nx, llint sum, llint use)
{
	if(nx == m){
		table[use>>(m/2)] = sum;
		return;
	}
	if((used & (1LL<<nx)) == 0) dfs2(used|G[nx], nx+1, sum+1, use|(1LL<<nx));
	dfs2(used, nx+1, sum, use);
}

void zeta_transform(llint a[], llint n)
{
	int S = 1<<n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(j&(1LL<<i)) a[j] = max(a[j], a[j^(1<<i)]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint t, id = 0, bs = 0; 
	string s;
	cin >> t;
	
	for(int i = 1; i <= n-1; i++){
		cin >> t;
		if(t == 2){
			cin >> s;
			if(!mp.count(s)) mp[s] = id++;
			bs |= 1LL<<mp[s];
		}
		else{
			vec.push_back(bs);
			bs = 0;
		}
	}
	vec.push_back(bs);
	
	if(m == 1){
		cout << 1 << endl;
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < vec.size(); k++){
				if( (vec[k]&(1LL<<i)) && (vec[k]&(1LL<<j)) ){
					G[i] |= (1LL<<j);
					break;
				}
			}
		}
	}
	
	//for(int i = 0; i < m; i++) cout << G[i] << " "; cout << endl;
	
	dfs(0, 0, 0);
	dfs2(0, m/2, 0, 0);
	zeta_transform(table, m-m/2);
	
	//for(int i = 0; i < vec2.size(); i++) cout << vec2[i].first << " " << vec2[i].second << endl;
	//for(int i = 0; i < (1<<(m-m/2)); i++) cout << table[i] << " "; cout << endl;
	
	llint ans = 0;
	for(int i = 0; i < vec2.size(); i++){
		llint hf = vec2[i].first >> (m/2);
		hf = ~hf;
		hf &= (1LL<<(m-m/2))-1;
		ans = max(ans, vec2[i].second + table[hf]);
	}
	cout << ans << endl;
	
	return 0;
}