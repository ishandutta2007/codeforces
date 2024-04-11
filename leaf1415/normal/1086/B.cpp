#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int n, s;
vector<int> G[100005];

int main(void)
{
	cin >> n >> s;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(n == 2){
		printf("%.11f\n", (double)s);
		return 0;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 1) cnt++;
	}
	
	double ans = s * (2.0 / (int)cnt);
	printf("%.11f\n", ans);
	return 0;
}