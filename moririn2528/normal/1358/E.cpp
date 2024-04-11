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

LL t[330000];
LL dif[330000];
LL mi[330000];

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	c=0;
	for(i=0;i<(n+1)/2;i++){
		cin>>t[i];
		c+=t[i];
	}
	cin>>m;
	for(i=0;i<(n+1)/2;i++){
		t[i]=m-t[i];
	}
	a=0;
	for(i=0;i<(n+1)/2;i++){
		a+=t[i];
		mi[i+1]=min({mi[i],mi[i+1],a});
	}
	for(i=n/2;i>=0;i--,c+=m){
		a=c+mi[i];
		if(a>0){
			cout<<n-i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}