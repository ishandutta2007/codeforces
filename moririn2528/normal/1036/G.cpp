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

vector<int> path[1100000];
vector<int> source,sink,num;
bool used[1100000];

void dfs(int pos){
	if(used[pos])return;
	used[pos]=true;
	for(auto to:path[pos])dfs(to);
}

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a--,b--;
		path[a].push_back(b);
		used[b]=true;
	}
	for(i=0;i<n;i++){
		if(!used[i])source.push_back(i);
		if(path[i].empty())sink.push_back(i);
	}
	p=source.size();
	for(i=0;i<p;i++){
		memset(used,false,sizeof(used));
		dfs(source[i]);
		a=0;
		for(j=0;j<p;j++){
			if(used[sink[j]])a+=1<<j;
		}
		num.push_back(a);
	}
	for(i=1;i<(1<<p)-1;i++){
		a=__builtin_popcount(i);
		b=0;
		for(j=0;j<p;j++){
			if((num[j]&~i)==0)b++;
		}
		if(a<=b){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}