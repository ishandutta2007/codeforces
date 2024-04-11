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
#include<set>
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

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=1e9+7){
	//p_a^p_n mod p_p
	long long int p_b=1,p_t=1;
	for(;p_b<=p_n;p_b<<=1);
	for(p_b>>=1;p_b>0;p_b>>=1){
		p_t*=p_t;
		if(p_t>=p_p)p_t%=p_p;
		if(p_n&p_b)p_t*=p_a;
		if(p_t>=p_p)p_t%=p_p;
	}
	return p_t;
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int x,y;
	LL s=1;
	string sa;
	set<int> s1;
	cin>>n;
	x=-INF,y=INF,c=0;
	for(i=0;i<n;i++){
		cin>>sa>>a;
		if(sa=="ADD"){
			if(x<a && a<y)c++;
			s1.insert(a);
			continue;
		}
		c=0;
		auto itr=s1.find(a);
		if(a<x || y<a){
			s=0;
			break;
		}
		if(x<a && a<y){
			s*=2;
			s%=MAX;
		}
		itr++;
		if(itr!=s1.end())y=*itr;
		else y=INF;
		itr--;
		if(itr==s1.begin())x=-INF;
		else{
			itr--;
			x=*itr;
		}
		s1.erase(a);
	}
	s*=c+1;
	s%=MAX;
	cout<<s<<endl;
}