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

int cnt[30];

int main(){
	LL n,m,x;
	int i,j,k;
	LL a,b,c;
	vector<LL> v1;
	cin>>n>>m>>x;
	b=0;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(a);
		for(j=0,k=0;j<30;j++){
			if(a&(1<<j))cnt[j]++,k=j;
		}
		if(b<k)b=k;
	}
	x=pow(x,m);
	LL s=0;
	for(i=0;i<n;i++){
		a=0;
		for(j=0;j<30;j++){
			if(v1[i]&(1<<j))c=1;
			else c=0;
			if(cnt[j]>c)a+=1<<j;
		}
		a|=v1[i]*x;
		s=max(s,a);
	}
	cout<<s<<endl;
}