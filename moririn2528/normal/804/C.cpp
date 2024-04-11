#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
	if(vec_n==-1)vec_n=vec_s.size();
	for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

vector<int> path[330000],path2[330000],ice[330000];
bool used[330000];
int col[330000];

void create_path(int pos){
	if(used[pos])return;
	used[pos]=true;
	for(auto to:path2[pos]){
		if(used[to])continue;
		path[pos].push_back(to);
		create_path(to);
	}
}

void dfs(int pos){
	memset(used,false,sizeof(bool)*ice[pos].size());
	for(auto node:ice[pos]){
		if(col[node]!=0)used[col[node]-1]=true;
	}
	int i=0;
	for(auto node:ice[pos]){
		if(col[node]!=0)continue;
		while(used[i])i++;
		col[node]=i+1,used[i]=true;
	}
	for(auto to:path[pos])dfs(to);
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>c;
		s=max(s,c);
		for(j=0;j<c;j++){
			cin>>a;
			a--;
			ice[i].push_back(a);
		}
	}
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		path2[a].push_back(b);
		path2[b].push_back(a);
	}
	create_path(0);
	dfs(0);
	s=max(s,1);
	cout<<s<<endl;
	for(i=0;i<m;i++){
		if(col[i]==0)col[i]=1;
	}
	array_show(col,m);
}