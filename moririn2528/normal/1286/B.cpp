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

vector<int> path[2200];
int ch[2200];
int t[2200];
int s[2200];
vector<int> v1;

int dfs(int pos){
	for(auto to:path[pos]){
		ch[pos]+=dfs(to);
	}
	return ch[pos]+1;
}

bool calc(int pos){
	if(t[pos]>ch[pos])return false;
	int a=v1[t[pos]];
	s[pos]=a;
	v1.erase(v1.begin()+t[pos]);
	for(auto to:path[pos]){
		if(!calc(to))return false;
	}
	return true;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int nest;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>t[i];
		a--;
		if(a==-1)nest=i;
		else path[a].push_back(i);
	}
	for(i=1;i<=n;i++){
		v1.push_back(i);
	}
	dfs(nest);
	if(calc(nest)){
		cout<<"YES"<<endl;
		array_show(s,n);
	}else cout<<"NO"<<endl;
}