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

map<int,int> m1;
vector<P> v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		m1[a]++;
	}
	for(auto node:m1){
		v1.push_back(make_pair(node.second,node.first));
	}
	sort(v1.rbegin(),v1.rend());
	a=0,j=0,c=0;
	for(i=n;i>0;i--){
		a+=j;
		while(v1[j].first==i)j++;
		b=n-a;
		if(i>b/i)continue;
		b=b/i*i;
		if(c<b)c=b,k=i;
	}
	a=k,b=c/k;
	cout<<c<<endl;
	cout<<a<<" "<<b<<endl;
	vector<vector<int> > vs(a,(vector<int>(b,0)));
	i=0,j=0;
	for(auto &node:v1){
		if(node.first>k)node.first=k;
		while(node.first--){
			vs[i][j]=node.second;
			i++,j++;
			if(i>=a)i-=a;
			if(j>=b)j-=b;
			if(vs[i][j]!=0)j++;
			if(j>=b)j-=b;
		}
	}
	for(i=0;i<a;i++){
		for(j=0;j<vs[i].size();j++){
			cout<<vs[i][j];
			if(j!=vs[i].size()-1)cout<<' ';
		}
		cout<<endl;
	}
}