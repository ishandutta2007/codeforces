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

LL solve(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<30;i++){
		if(n<((LL)1<<(2*i)))break;
	}
	a=i-1;
	LL s=0;
	if(n<=3)return n;
	s=n%3;
	if(s==0)s=3;
	int p=s;
	s<<=(2*a);
	n-=(LL)1<<(2*a);
	if(n<3)return s;
	n/=3;
	p--;
	for(i=0;i<a;i++){
		b=n>>(2*i);
		b%=4;
		if(b==0)continue;
		b+=p;
		b%=3;
		if(b==0)b=3;
		s+=b<<(2*i);
	}
	return s;
}

int main(){
	int n,i;
	init();
	cin>>n;
	for(i=0;i<n;i++){
		LL s=solve();
		cout<<s<<endl;
	}
}