#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MAXF 2097152
int n;

int bit[MAXF];
int sum(int i){
	int s = 0;
	while(i > 0){
		s ^= bit[i];
		i -= (i & -i);
	}
	return s;
}
void upd(int i, int v){
	if(i == 0) return;
	while(i < MAXF){
		bit[i] ^= v;
		i += (i & -i);
	}
}
int a[1100000];
int main(){
	for(int i = 0; i < MAXF; i++) bit[i] = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int m;
	scanf("%d", &m);
	pair<int,int> q[m];
	pair<int,int> s[m];
	for(int i = 0; i < m; i++){
		scanf("%d%d", &q[i].first, &q[i].second);
		s[i] = q[i];
	}
	map<pair<int,int>, int> ans;
	sort(s,s+m);
	reverse(s,s+m);
	map<int,int> next;
	int z = n;
	for(int i = 0; i < m; i++){
		while(z >= s[i].first){
			upd(next[a[z]],a[z]);
			next[a[z]] = z;
			z--;
		}
		ans[s[i]] = sum(s[i].second);
	}
	for(int i = 0; i < m; i++){
		printf("%d\n", ans[q[i]]);
	}
}