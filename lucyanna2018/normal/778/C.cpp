#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;
#define ran 333333
int n;
vector<pair<int,char> > e[ran];
int depth[ran];
int cnt[ran],sum[ran];
int mg[ran];
int res[ran];
void dfs(int x){
	sum[x] = 1;
	for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = it->first;
		depth[y] = depth[x] + 1;
		dfs(y);
		sum[x] += sum[y];
	}
}

int trie[ran][26],z;
void dfs3(int x,int pos){
	for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = it->first;
		int to = it->second - 'a';
		if(trie[pos][to] == 0){
			++z;
			memset(trie[z],0,sizeof(trie[z]));
			trie[pos][to] = z;
		}
		dfs3(y, trie[pos][to]);
	}
}
void dfs4(int x,int pos){
	for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = it->first;
		int to = it->second - 'a';
		if(trie[pos][to] == 0){
			z += sum[y];
		}
		else
			dfs4(y, trie[pos][to]);
	}
}

void dfs2(int x){
	if(e[x].size() == 0){
		mg[x] = 1;
	}else{
		z = 1;
		memset(trie[z],0,sizeof(trie[z]));
		int t = -1;
		for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y = it->first;
			if(t == -1 || sum[y] > sum[t])
				t = y;
		}
		for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
			int y = it->first;
			if(y != t)
				dfs3(y,1);
		}
		dfs4(t, 1);
		mg[x] = z;
/*	if(e[x].size() == 1){
		mg[x] = sum[x]-1;
	}else{
		z = 1;
		memset(trie[z],0,sizeof(trie[z]));
		for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++)
			dfs3(it->first,1);
		mg[x] = z;
	}*/
	}
	for(vector<pair<int,char> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = it->first;
		dfs2(y);
	}
}
int main(){
	char s[9];
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d%s",&u,&v,s);
		e[u].push_back(make_pair(v,*s));
	}
	depth[1] = 0;
	dfs(1);
	int maxdepth = 0;
	for(int i=1; i<=n; i++){
		cnt[depth[i]]++;
		maxdepth = max(depth[i],maxdepth);
	}
	for(int i=2; i<=maxdepth; i++)
		res[i] = res[i-1] + cnt[i-2];
	dfs2(1);
//	for(int i=1; i<=n; i++)printf("%d\n",mg[i]);
	for(int i=1; i<=n; i++)
		res[depth[i]+1] += mg[i];
	int t = -1;
	for(int i=1; i<=maxdepth; i++)
		if(t == -1 || res[i] < res[t])
			t = i;
	printf("%d\n%d\n",res[t],t);
	return 0;
}