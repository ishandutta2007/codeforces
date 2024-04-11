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
const LL INF=(LL)1<<60;
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

int n,m;
vector<P> path[330000];
vector<LL> v1,v2;
vector<char> used;

int dfs1(int pos,int bef){
	v1.push_back(pos);
	if(pos==n-1)return 1;
	for(auto to:path[pos]){
		if(to.first==bef)continue;
		v2.push_back(to.second);
		if(dfs1(to.first,pos))return 1;
		v2.pop_back();
	}
	v1.pop_back();
	return 0;
}

LL dfs2(int pos,int bef){
	LL s=0;
	for(auto to:path[pos]){
		if(to.first==bef)continue;
		if(used[to.first])continue;
		s=max(s,dfs2(to.first,pos)+to.second);
	}
	return s;
}

int dfs_size(int pos,int bef){
	int s=0;
	for(auto to:path[pos]){
		if(to.first==bef)continue;
		if(used[to.first])continue;
		s+=dfs_size(to.first,pos);
	}
	return s+1;
}

int main(){
	int i,j,k;
	LL a,b,c;
	LL s=INF;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	used.assign(n,0);
	for(i=0;i<n-1;i++){
		cin>>a>>b>>c;
		a--,b--;
		path[a].push_back(make_pair(b,c));
		path[b].push_back(make_pair(a,c));
	}
	dfs1(0,-1);
	for(auto num:v1)used[num]=1;
	b=INF;
	n=v1.size();
	for(i=0;i<n;i++){
		int num=v1[i];
		used[num]=0;
		a=dfs_size(num,-1);
		if(a>2){
			s=-1;
			break;
		}
		if(a==2){
			a=dfs2(num,-1);
			if(i){
				s=min(s,b-a);
				s=min(s,v2[i-1]-a);
			}
			if(i<n-1)s=min(s,v2[i]-a);
			b=min(b,-a);
		}
		if(i<n-1)b+=v2[i];
		used[num]=1;
	}
	for(i=0;i<n-2;i++){
		s=min(s,v2[i]+v2[i+1]);
	}
	b=0;
	for(auto num:v2)b+=num;
	for(i=0;i<m;i++){
		cin>>a;
		if(a<s)a=b-s+a;
		else a=b;
		cout<<a<<endl;
	}
}