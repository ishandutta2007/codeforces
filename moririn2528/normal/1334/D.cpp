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

vector<int> v1;

void solve(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	LL l,r;
	cin>>n>>l>>r;
	l--;
	v1.clear();
	a=0;
	for(i=0;i<n-1;i++){
		if(a+2*(n-i-1)<l){
			a+=2*(n-i-1);
			continue;
		}
		if(a>=r)break;
		for(j=i+1;j<n;j++){
			if(l<=a && a<r)v1.push_back(i+1);
			a++;
			if(l<=a && a<r)v1.push_back(j+1);
			a++;
		}
	}
	if(l<=a && a<r)v1.push_back(1);
	array_show(v1);
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		solve();
	}
}