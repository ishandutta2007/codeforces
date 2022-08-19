#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> stuff[300000];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int p[n];
	for(int i = 0; i < n; i++){
		int b;
		scanf("%d", &b);
		p[b-1] = i;
	}
	pair<int,int> bad[m];
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a = p[a-1];
		b = p[b-1];
		if(a > b){
			swap(a,b);
		}
		stuff[a].push_back(b);
	}
	int sm = n;
	LL ans = 0;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < stuff[i].size(); j++){
			sm = min(sm, stuff[i][j]);
		}
		LL r = sm-i;
		ans += r;
	}
	printf("%I64d\n", ans);
}