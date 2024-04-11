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
typedef pair<LL,LL> P;
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

vector<vector<P> > path2,path;
vector<LL> used,num;

void create_path(int a){
	if(used[a])return;
	used[a]=1;
	for(auto node:path2[a]){
		int b=node.first;
		if(used[b])continue;
		path[a].push_back(node);
		create_path(b);
	}
}

LL ds;
LL dfs(int a){
	LL s=0,b=0;
	for(auto node:path[a]){
		b=dfs(node.first);
		s+=b;
		ds+=b*node.second;
		num[a]+=num[node.first];
	}
	num[a]++;
	return 1-s%2;
}

LL dfs2(int a){
	LL s=0;
	for(auto node:path[a]){
		s+=dfs2(node.first);
		s+=num[node.first]*node.second;
		num[a]+=num[node.first];
	}
	num[a]++;
	return s;
}

LL gravity_shift(int a,int n,int pa=-1){
	for(auto node:path[a]){
		if(num[node.first]*2>=n)return gravity_shift(node.first,n,a);
	}
	return a;
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	LL s[2];
	int tes;
	cin>>tes;
	while(tes--){
		cin>>n;
		path2.assign(2*n,vector<P>(0));
		path.assign(2*n,vector<P>(0));
		used.assign(2*n,0);
		num.assign(2*n,0);
		for(i=0;i<2*n-1;i++){
			cin>>a>>b>>c;
			a--,b--;
			path2[a].push_back(make_pair(b,c));
			path2[b].push_back(make_pair(a,c));
		}
		create_path(0);
		ds=0;
		dfs(0);
		s[0]=ds;
		a=gravity_shift(0,2*n);
		path.assign(2*n,vector<P>(0));
		used.assign(2*n,0);
		num.assign(2*n,0);
		create_path(a);
		s[1]=dfs2(a);
		cout<<s[0]<<" "<<s[1]<<endl;
		i=0;
	}
}