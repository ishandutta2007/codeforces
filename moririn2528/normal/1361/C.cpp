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

int n,m;
int t[550000][2];
vector<int> vs;
vector<vector<P>> v1;
vector<char> used;

void dfs(int pos,int p,int mod){
	int a,b,c;
	while(!v1[pos].empty()){
		while(!v1[pos].empty() && used[v1[pos].back().second])v1[pos].pop_back();
		if(v1[pos].empty())break;
		a=v1[pos].back().first,b=v1[pos].back().second;
		v1[pos].pop_back(),used[b]=1;
		dfs(a,b,mod);
	}
	if(p==-1)return;
	if((t[p][0]&mod)==pos){
		vs.push_back(p*2+1);
		vs.push_back(p*2+2);
	}else{
		vs.push_back(p*2+2);
		vs.push_back(p*2+1);
	}
}

bool check(int mod){
	int i,j,k;
	int a,b,c;
	c=(1<<mod)-1;
	v1.assign(1<<mod,vector<P>());
	used.assign(n,0);
	vs.clear();
	for(i=0;i<n;i++){
		a=t[i][0]&c,b=t[i][1]&c;
		v1[a].push_back(make_pair(b,i));
		v1[b].push_back(make_pair(a,i));
	}
	for(i=0;i<c;i++){
		if(v1[i].size()%2)return false;
	}
	dfs(a,-1,c);
	if(vs.size()!=2*n)return false;
	a=t[(vs[0]-1)/2][(vs[0]-1)%2]&c;
	b=t[(vs.back()-1)/2][(vs.back()-1)%2]&c;
	if(a!=b)return false;
	return true;
}

int main(){
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			cin>>t[i][j];
		}
	}
	int z[3]={0,21};
	while(z[1]-z[0]>1){
		z[2]=(z[0]+z[1])/2;
		if(check(z[2]))z[0]=z[2];
		else z[1]=z[2];
	}
	check(z[0]);
	printf("%d\n",z[0]);
	array_show(vs);
}