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

vector<int> path[200005],path2[200005];
vector<int> v1;

bool used[200005];

void create_tree(int a){
	used[a]=true;
	for(auto to:path[a]){
		if(used[to])continue;
		used[to]=true;
		path2[a].push_back(to);
	}
	for(auto to:path2[a])create_tree(to);
}

void dfs(int a){
	v1.push_back(a);
	for(auto to:path2[a]){
		dfs(to);
		v1.push_back(a);
	}
}

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	cin>>n>>m>>p;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	create_tree(0);
	dfs(0);
	for(j=0,k=0;j<p;j++){
		if(j<v1.size()%p)a=v1.size()/p+1;
		else a=v1.size()/p;
		cout<<a<<' ';
		a+=k;
		for(;k<a;k++){
			cout<<v1[k]+1<<((k==a-1)?'\n':' ');
		}
	}
}