#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
using namespace std;
#define ran 111111

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}

int n,res;
vector<pair<int,int> > e[ran];
vector<pair<int,int> > q[ran];
int fat[ran];
int u[ran],v[ran];
int p2[1111111];

int ace[ran],d[ran];
int ancestor(int x){return x-ace[x]?ace[x]=ancestor(ace[x]):x;}

void tarjan(int x){
	ace[x]=x;
	for(vector<pair<int,int> >::iterator it=q[x].begin(); it!=q[x].end(); it++){
		int y=it->first;
		if(d[y]==-1)continue;
		int lca = ancestor(y);

		if(it->second == 1){//x -> lca -> y
			u[x]++;
			v[y]++;
		}else{
			u[y]++;
			v[x]++;
		}
		u[lca]--;
		v[lca]--;
	}
	for(vector<pair<int,int> >::iterator it=e[x].begin(); it!=e[x].end(); it++){
		int y=it->first;
		if(y==fat[x])continue;
		d[y]=d[x]+1;
		fat[y]=x;
		tarjan(y);
		ace[y]=x;
	}
}
void dfs(int x){
	for(vector<pair<int,int> >::iterator it = e[x].begin(); it!=e[x].end(); it++){
		int y = it->first;
		if(y == fat[x])continue;
		dfs(y);
		if(it->second == 1){
			res = add(res,p2[u[y]]);
		}else
		if(it->second == -1)
			res = add(res,p2[v[y]]);
		u[x] += u[y];
		v[x] += v[y];
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		e[i].clear();
		q[i].clear();
		u[i] = v[i] = 0;
		d[i] = -1;
	}
	for(int i=1; i<n; i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,-z));
	}
	int Q,Z=1;
	scanf("%d",&Q);
	for(int i=0; i<Q; i++){
		int x;
		scanf("%d",&x);
		q[Z].push_back(make_pair(x,1));
		q[x].push_back(make_pair(Z,-1));
		Z = x;
	}
	fat[1]=1;
	d[1]=1;
	tarjan(1);
	p2[0] = 0;
	for(int i=1; i<=Q; i++)
		p2[i] = add(add(p2[i-1],p2[i-1]),1);
	res=0;
	dfs(1);
	printf("%d\n",res);
}

int main(){
	solve();
	return 0;
}