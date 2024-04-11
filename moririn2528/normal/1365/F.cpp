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

bool solve(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n;
	vector<int> v1(n),v2(n);
	map<P,int> m1;
	for(i=0;i<n;i++){
		cin>>v1[i];
	}
	for(i=0;i<n/2;i++){
		a=v1[i],b=v1[n-i-1];
		if(a>b)swap(a,b);
		m1[make_pair(a,b)]++;
	}
	for(i=0;i<n;i++){
		cin>>v2[i];
	}
	for(i=0;i<n/2;i++){
		a=v2[i],b=v2[n-i-1];
		if(a>b)swap(a,b);
		m1[make_pair(a,b)]--;
	}
	for(auto node:m1){
		if(node.second)return false;
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(i=0;i<n;i++){
		if(v1[i]!=v2[i])return false;
	}
	return true;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		if(solve())cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}