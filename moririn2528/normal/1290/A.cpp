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

vector<int> v1,v2;
deque<P> d1;

int main(){
	int n,m,p;
	int i,j,k;
	int a,b,c;
	int tes;
	cin>>tes;
	while(tes--){
		cin>>n>>m>>p;
		v1.clear(),v2.clear(),d1.clear();
		for(i=0;i<n;i++){
			cin>>a;
			v1.push_back(a);
		}
		a=n-m;
		for(i=0;i<m;i++){
			v2.push_back(max(v1[i],v1[i+a]));
		}
		a=m-p;
		if(a<=0)a=1;
		for(i=0;i<a;i++){
			while(!d1.empty() && d1.back().first>=v2[i])d1.pop_back();
			d1.push_back(make_pair(v2[i],i));
		}
		int s=d1.front().first;
		for(i=0;i<(int)v2.size()-a;i++){
			while(!d1.empty() && d1.back().first>=v2[i+a])d1.pop_back();
			d1.push_back(make_pair(v2[i+a],i+a));
			if(d1.front().second==i)d1.pop_front();
			s=max(s,d1.front().first);
		}
		cout<<s<<endl;
	}
}