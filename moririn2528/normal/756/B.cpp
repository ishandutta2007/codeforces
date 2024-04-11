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

int s[220000];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	vector<int> v1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
	}
	for(i=0;i<n;i++){
		a=v1[i];
		s[i+1]=s[i]+20;
		auto itr=upper_bound(v1.begin(),v1.end(),a-90);
		b=distance(v1.begin(),itr);
		s[i+1]=min(s[i+1],s[b]+50);
		itr=upper_bound(v1.begin(),v1.end(),a-1440);
		b=distance(v1.begin(),itr);
		s[i+1]=min(s[i+1],s[b]+120);
	}
	for(i=0;i<n;i++){
		s[i]=s[i+1]-s[i];
	}
	array_show(s,n,'\n');
}