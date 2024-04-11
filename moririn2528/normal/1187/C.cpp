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

int t[1111];
int s[1111];
vector<P> v1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		b--,c--;
		if(a==1)t[b]++,t[c]--;
		else v1.push_back(make_pair(b,c));
	}
	s[0]=1e5;
	for(i=0;i<n;i++){
		t[i+1]+=t[i];
		s[i+1]=s[i];
		if(t[i]>0)s[i+1]++;
		else s[i+1]--;
	}
	for(auto node:v1){
		a=node.first,b=node.second;
		for(i=a;i<b;i++){
			if(s[i]>s[i+1])break;
		}
		if(i==b){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	array_show(s,n);
}