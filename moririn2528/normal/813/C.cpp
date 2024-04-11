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

vector<int> path2[220000],path[220000];
int num[220000];
int dep[220000];
int par[220000];

void dfs(int pos,int bef=-1){
	for(auto to:path2[pos]){
		if(to==bef)continue;
		path[pos].push_back(to);
		par[to]=pos;
		dfs(to,pos);
	}
}

int count(int pos,int s=0){
	dep[pos]=s;
	int a=0;
	for(auto to:path[pos]){
		a=max(a,count(to,s+1));
	}
	num[pos]=a;
	return a+1;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	m--;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		path2[a].push_back(b);
		path2[b].push_back(a);
	}
	dfs(0);
	count(0);
	a=dep[m];
	a=(a-1)/2;
	b=dep[m]-a;
	for(i=0;i<a;i++){
		m=par[m];
	}
	b+=num[m];
	cout<<b*2<<endl;
}