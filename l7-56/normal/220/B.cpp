#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxk = 450;
// 447
int a[maxn],n,m;
map <int, int> CNT;
int sum[maxn][maxk];

vector <int> v;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if(a[i] > n) a[i] = 0;
		else CNT[a[i]]++;
	}
	
	for(int i = 1; i <= n; ++i){
		if(a[i] && CNT[a[i]] < a[i]) a[i] = 0;
		if(a[i] && CNT[a[i]] >= a[i]) v.push_back(a[i]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int K = v.size();
	for(int i = 1; i <= n; ++i){
		for(int k = 1; k <= K; ++k)
			sum[i][k] = sum[i - 1][k];
		if(a[i]) {
			int kd = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
			sum[i][kd]++;
		}
	}
	
	while(m--){
		int l,r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for(int k = 1; k <= K; ++k)
			ans += (sum[r][k] - sum[l - 1][k] == v[k - 1]);
		printf("%d\n", ans);
	}
	
	return 0;
}
//CF220B