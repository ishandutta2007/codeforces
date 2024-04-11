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
vector<pair<LL,LL> > v1;

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=1;i<2e6;i++){
		a+=i,b+=i*i;
		if(n<b)break;
		c=n-b;
		if(c%a)continue;
		c/=a;
		v1.push_back(make_pair(i,i+c));
		if(c)v1.push_back(make_pair(i+c,i));
	}
	sort(v1.begin(),v1.end());
	cout<<v1.size()<<endl;
	for(auto node:v1){
		cout<<node.first<<" "<<node.second<<endl;
	}
}