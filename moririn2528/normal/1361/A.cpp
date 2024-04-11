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

vector<int> path[550000];
int t[550000][2];
int s[550000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int cnt=0;
	vector<P> v1;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--;b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<n;i++){
		cin>>t[i][0];
		v1.push_back(make_pair(t[i][0],i));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		a=v1[i].first,b=v1[i].second;
		if(t[b][1]!=a-1){
			cout<<-1<<endl;
			return 0;
		}
		s[i]=b+1;
		for(auto to:path[b]){
			if(t[to][1]==a-1)t[to][1]=a;
		}
	}
	array_show(s,n);
}