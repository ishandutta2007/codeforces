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

vector<pair<LL,LL> > v1;
vector<int> vs;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	LL p,q;
	cin>>n;
	if(n==2){
		cout<<1<<endl;
		cout<<1<<endl;
		return 0;
	}
	cin>>p>>q;
	c=0;
	for(i=0;i<n-1;i++){
		cin>>a>>b;
		a-=p,b-=q;
		v1.push_back(make_pair(a,b));
		a+=b;
		if(a<0)a=-a;
		if(a%2==0)c++;
	}
	while(c==n-1){
		for(auto &node:v1){
			a=node.first-node.second,b=node.first+node.second;
			node=make_pair(a/2,b/2);
		}
		c=0;
		for(auto node:v1){
			a=node.first+node.second;
			if(a<0)a=-a;
			if(a%2==0)c++;
		}
	}
	for(i=0;i<n-1;i++){
		a=v1[i].first+v1[i].second;
		if(a<0)a=-a;
		if(a%2==1){
			vs.push_back(i+2);
		}
	}
	cout<<vs.size()<<endl;;
	array_show(vs);
}