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

LL num[110000];
vector<tuple<int,int,LL> > vs;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		num[a]-=c,num[b]+=c;
	}
	j=0;
	for(i=0;i<n;){
		if(num[i]>=0){
			i++;
			continue;
		}
		for(;j<n && num[j]<=0;j++);
		a=min(-num[i],num[j]);
		num[i]+=a,num[j]-=a;
		vs.push_back(make_tuple(i+1,j+1,a));
	}
	cout<<vs.size()<<endl;
	for(auto node:vs){
		tie(a,b,c)=node;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
}