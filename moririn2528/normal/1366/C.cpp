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

void init(){
	
}

void solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	vector<P> mt(n+m,make_pair(0,0));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a;
			b=min(i+j,n+m-2-i-j);
			if(a)mt[b].first++;
			else mt[b].second++;
		}
	}
	a=0;
	for(i=0;i<(n+m-1)/2;i++){
		a+=min(mt[i].first,mt[i].second);
	}
	cout<<a<<endl;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}