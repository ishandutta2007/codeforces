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

vector<int> v1[100005];
bool used[100005];
bool bad[100005];
vector<int> path[100005],vs;

bool check(int t){
	if(used[t])return true;
	used[t]=true;
	if(t)vs.push_back(t);
	if(bad[t])return false;
	for(auto to:path[t]){
		if(!check(to))return false;
	}
	return true;
}

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		for(j=0;j<a;j++){
			cin>>b;
			v1[i].push_back(b);
		}
		v1[i].push_back(0);
	}
	for(i=0;i<n-1;i++){
		p=min(v1[i].size(),v1[i+1].size());
		for(j=0;j<p;j++){
			a=v1[i][j],b=v1[i+1][j];
			if(a==b)continue;
			if(a<b){
				path[b].push_back(a);
			}else{
				path[0].push_back(a);
				bad[b]=true;
			}
			break;
		}
	}
	if(check(0)){
		cout<<"Yes"<<endl;
		cout<<vs.size()<<endl;
		array_show(vs);
	}else cout<<"No"<<endl;
}