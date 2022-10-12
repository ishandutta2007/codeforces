/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/

#define ran 222222
int n,m,k;
int deg[ran];
int q[ran],lq;
int res[ran];
vector<int> e[ran];
int minv[ran], maxval[ran];
bool used[ran];

set<int> unused;
priority_queue<pair<int,int> > pri;

bool nosol(){
	if(n < k)return true;
	for(int i=1; i<=n; i++)
		if(deg[i] == 0)
			q[lq++] = i;
	for(int j=0; j<n; j++){
		if(j == lq)return true;
		int x = q[j];
		for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
			int y = *it;
			if(--deg[y] == 0){
				q[lq++] = y;
			}
			if(res[x] != 0 && res[y] != 0 && res[x] <= res[y])
				return true;
		}
	}
	for(int i=1; i<=n; i++){
		minv[i] = res[i] == 0 ? 1 : res[i];
		maxval[i] = res[i] == 0 ? k : res[i];
	}
	for(int j=0; j<n; j++){
		int x = q[j];
		for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
			int y = *it;
			maxval[y] = min(maxval[y], maxval[x] - 1);
		}
	}
	for(int j=n-1; j>=0; j--){
		int x = q[j];
		for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
			int y = *it;
			minv[x] = max(minv[x], minv[y] + 1);
		}
	}
	for(int i=1; i<=n; i++)
		if(minv[i] > maxval[i])
			return true;

	memset(deg,0,sizeof(deg));
	for(int i=1; i<=n; i++)
		for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); it++){
			deg[*it] ++;
		}
	for(int i=1; i<=n; i++)
		if(deg[i]==0)
			pri.push(make_pair(minv[i],i));
	while(!pri.empty()){
		int x = pri.top().second;
		pri.pop();

		set<int>::iterator it = unused.upper_bound(maxval[x]);
		if(it == unused.begin())
			res[x] = maxval[x];
		else{
			--it;
			if(*it < minv[x])
				res[x] = maxval[x];
			else
				res[x] = maxval[x] = *it;
		}
		unused.erase(res[x]);

		for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
			int y = *it;
			maxval[y] = min(maxval[y], maxval[x] - 1);
			if(--deg[y] == 0){
				pri.push(make_pair(minv[y], y));
			}
		}
	}
	return !unused.empty();
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=k; i++)
		unused.insert(i);
	for(int i=1; i<=n; i++){
		scanf("%d",&res[i]);
		unused.erase(res[i]);
	}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		deg[y] ++;
	}
	if(nosol()){
		puts("-1");
	}else
		for(int i=1; i<=n; i++)
			printf("%d%c",res[i],i<n?' ':'\n');
	return 0;
}