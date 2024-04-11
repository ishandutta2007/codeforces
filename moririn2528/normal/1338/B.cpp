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

vector<int> path[110000];
bool used[110000];
int leaf=-1;

bool dfs1(int pos,int bef=-1,int oe=0){
	if(path[pos].size()==1){
		if(leaf==-1)leaf=oe;
		else if(leaf!=oe)return false;
		else return true;
	}
	for(auto to:path[pos]){
		if(to==bef)continue;
		if(!dfs1(to,pos,1-oe))return false;
	}
	return true;
}

int dfs2(int pos,int bef=-1){
	int s=0;
	bool bl=false;
	for(auto to:path[pos]){
		if(to==bef)continue;
		s+=dfs2(to,pos);
		if(path[to].size()==1){
			if(!bl)s++;
			bl=true;
		}else s++;
	}
	return s;
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
	int pos;
	for(pos=0;pos<n;pos++){
		if(path[pos].size()!=1)break;
	}
	int s[2]={0};
	if(dfs1(0))s[0]=1;
	else s[0]=3;
	s[1]=dfs2(pos);
	cout<<s[0]<<" "<<s[1]<<endl;
}