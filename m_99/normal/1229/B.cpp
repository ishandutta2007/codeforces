#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int ans = 0;

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

void check(int parent,int now,vector<long long> &x,vector<vector<int>> &E,map<long long,int> mp){
	mp[x[now]]++;
	map<long long,int> new_mp;
	for(auto a:mp){
		long long X = a.first;
		X = gcd(X,x[now]);
		new_mp[X] += a.second;
		ans = mod(ans + mod(X * a.second));
	}
	
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		check(now,to,x,E,new_mp);
	}
}
int main(){
	int N;
	cin>>N;
	
	vector<long long> x(N);
	for(int i=0;i<N;i++)cin>>x[i];
	
	vector<vector<int>> E(N,vector<int>());
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	map<long long,int> mp;
	check(-1,0,x,E,mp);
	
	cout<<ans<<endl;
	
	
	return 0;
}