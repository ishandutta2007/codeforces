#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a, b, id;
	bool operator < (const node &o) const{
		return a * o.b < o.a * b;
	}
};
int n, par[1001001], last[1001001];
ll a[1001001], j[1001001], m[1001001];
priority_queue<node> pq;
double ans[1001001];
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
void merge(int a, int b){
	last[a] = last[b];
	j[a] += j[b];
	m[a] += m[b];
	par[b] = a;
}
bool cmp(ll a, ll b){
	return j[a] * m[b] < j[b] * m[a];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) par[i] = i, last[i] = i, j[i] = a[i], m[i] = 1;
 	for(int i=1;i<=n;i++) pq.push({a[i], 1, i});

 	while(!pq.empty()){
 		ll u = pq.top().id;
 		pq.pop();
 		if(f(u) != u) continue;
 		if(last[u] == n || cmp(u, last[u]+1)) continue;
 		merge(u, last[u]+1);
 		pq.push({j[u], m[u], u});
 	}
 	for(int i=1;i<=n;i++){
 		for(int k=i;k<=last[i];k++) ans[k] = (double)j[i] / m[i];
 		i = last[i];
 	}

 	for(int i=1;i<=n;i++) printf("%.11f\n",ans[i]);
}