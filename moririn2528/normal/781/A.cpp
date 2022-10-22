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

vector<int> path[200005];

int co[200005];
int used[200005];
int used_node[200005];

void check(int a){
	if(used_node[a])return;
	used_node[a]=true;
	int i,j,k;
	used[co[a]]=a;
	for(auto to:path[a]){
		if(co[to]==-1)continue;
		used[co[to]]=a;
	}
	j=1;
	for(auto to:path[a]){
		if(co[to]!=-1)continue;
		for(;used[j]==a;j++);
		co[to]=j++;
	}
	for(auto to:path[a]){
		if(!used_node[to])check(to);
	}
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	memset(co,-1,sizeof(co));
	memset(used,-1,sizeof(used));
	co[0]=1;
	check(0);
	a=0;
	for(i=0;i<n;i++){
		a=max(a,co[i]);
	}
	cout<<a<<endl;
	array_show(co,n);
}