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
#include<cassert>
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

vector<vector<int>> path,rpath;
vector<int> num,num2,vt;

void init(){
	
}

void dfs1(int pos,int& a){
	if(num[pos]!=-1)return;
	num[pos]=-2;
	for(auto to:path[pos]){
		dfs1(to,a);
	}
	num[pos]=a;
	num2[a]=pos;
	a++;
}

void dfs2(int pos,int a){
	if(vt[pos]!=-1)return;
	vt[pos]=a;
	for(auto to:rpath[pos]){
		dfs2(to,a);
	}
}

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	scanf("%d%d",&n,&m);
	path.assign(n,vector<int>());
	rpath.assign(n,vector<int>());
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a--,b--;
		path[a].push_back(b);
		rpath[b].push_back(a);
	}
	num.assign(n,-1);
	num2.assign(n,-1);
	vt.assign(n,-1);
	a=0;
	for(i=0;i<n;i++){
		dfs1(i,a);
	}
	for(i=n-1;i>=0;i--){
		dfs2(num2[i],i);
	}
	a=n;
	for(auto num:vt){
		a=min(a,num);
	}
	vector<int> v1,v2;
	for(i=0;i<n;i++){
		if(vt[i]==a)v1.push_back(i+1);
		else v2.push_back(i+1);
	}
	if(v1.empty() || v2.empty()){
		printf("No\n");
		return;
	}
	printf("Yes\n");
	printf("%d %d\n",v1.size(),v2.size());
	array_show(v1);
	array_show(v2);
}

int main(){
	int n,i;
	init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		solve();
	}
}