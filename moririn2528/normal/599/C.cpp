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

int t[110000];
vector<P> v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	memset(t,-1,sizeof(t));
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(a,i));
	}
	sort(v1.begin(),v1.end());
	for(i=0;i<n;i++){
		j=v1[i].second;
		t[i]=max(j,t[i]);
		t[j]=max(i,t[j]);
	}
	a=0;
	for(i=0,j=-1;i<n;i++){
		j=max(j,t[i]);
		if(j==i)a++;
	}
	cout<<a<<endl;
}