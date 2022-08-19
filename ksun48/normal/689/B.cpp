#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[200000];
int dist[200000];
int stuff[1000000];
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++){
		if(i < n-1); edges[i].push_back(i+1);
		if(i > 0); edges[i].push_back(i-1);
		if(a[i]-1 != i) edges[i].push_back(a[i]-1);
	}
	for(int i = 0; i < n; i++){
		dist[i] = 10000000;
	}
	int s = 0;
	int e = 0;
	stuff[e++] = 0;
	dist[0] = 0;
	while(s < e){
		for(int i = 0; i < edges[stuff[s]].size(); i++){
			if(dist[edges[stuff[s]][i]] > dist[stuff[s]] + 1){
				dist[edges[stuff[s]][i]] = dist[stuff[s]] + 1;
				stuff[e++] = edges[stuff[s]][i];
			}
		}
		s++;
	}
	for(int i = 0; i < n; i++){
		printf("%d ", dist[i]);
	}
}