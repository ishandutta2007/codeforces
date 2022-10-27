
#include<bits/stdc++.h>
 
using namespace std;
const int MAXN = 100100;
 
#define int long long
 
vector<int> s[MAXN];
pair<int,int> g[MAXN];
 
signed main(){
	memset(g,0,sizeof g);
	
	int n,m;
	scanf("%lld %lld",&n,&m);
	
	for(int i = 1;i <= m;i++){
		int x,y;
		scanf("%lld %lld",&x,&y);
		
		if(x > y) s[y].push_back(x) , g[y].first ++ , g[x].second ++; 
		else s[x].push_back(y) , g[x].first ++ , g[y].second ++; 
	}
	
	int resp = 0;
	
	for(int i = 1;i <= n;i++) resp += g[i].first * g[i].second;
	
	//for(int i = 1;i <= n;i++) cout << "// " << i << " " << g[i].first << " " << g[i].second << endl;
	
	int q;
	scanf("%lld",&q);
	
	printf("%lld\n",resp);
	
	for(int i = 1;i <= q;i++){
		int x;
		scanf("%lld",&x);
		
		resp -= g[x].first * g[x].second;
	
		for(auto j : s[x]){
			
			g[j].second --;
			
			resp -= g[j].first;
			resp += g[j].second;
			g[j].first ++;
			s[j].push_back(x);
		}
		
		g[x].second = g[x].second + g[x].first , g[x].first = 0;
		s[x].clear();
		
		printf("%lld\n",resp);	
	}
	
}