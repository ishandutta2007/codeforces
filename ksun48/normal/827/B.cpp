#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int last[k];
	int num[k];
	for(int i = 0; i < k; i++){
		num[i] = 0;
		last[i] = 1;
	}
	vector<int> e1, e2;
	for(int i = 2; i <= n; i++){
		e1.push_back(last[(i-2)%k]);
		last[(i-2)%k] = i;
		e2.push_back(i);
		num[(i-2)%k]++;
	}
	printf("%d\n", num[0] + num[1]);
	for(int i = 0; i < e1.size(); i++){
		printf("%d %d\n", e1[i], e2[i]);
	}
}