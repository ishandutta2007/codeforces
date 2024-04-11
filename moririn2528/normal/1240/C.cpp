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
#include<set>
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

void init(){
	
}

vector<vector<P>> path;
vector<P> num;
int n,m;

void dfs(int pos,int bef){
	vector<LL> v1;
	LL a,b;
	LL s=0;
	for(auto node:path[pos]){
		if(node.first==bef)continue;
		dfs(node.first,pos);
		a=num[node.first].second;//not used
		b=num[node.first].first+node.second;//used
		if(b>a)v1.push_back(b-a);
		s+=a;
	}
	if(v1.size()<m){
		for(auto t:v1)s+=t;
		num[pos].first=s,num[pos].second=s;
		return;
	}
	sort(v1.rbegin(),v1.rend());
	for(int i=0;i<m-1;i++){
		s+=v1[i];
	}
	num[pos].first=s;
	num[pos].second=s+v1[m-1];
}

void solve(){
	int i,j,k;
	int a,b,c;
	scanf("%d%d",&n,&m);
	path.assign(n,vector<P>());
	num.assign(n,make_pair(0,0));
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		path[a].push_back(make_pair(b,c));
		path[b].push_back(make_pair(a,c));
	}
	dfs(0,-1);
	printf("%lld\n",num[0].second);
}

int main(){
	int n,i;
	init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		solve();
	}
}