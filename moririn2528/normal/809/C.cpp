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
typedef pair<LL,LL> P;
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

P calc(LL x,LL y,LL t){
	if(x>y)swap(x,y);
	if(x==0)return make_pair(0,0);
	int i,j,k;
	LL a,b,c;
	P pa;
	for(i=0;(1<<i)<=y;i++);
	i--;
	a=1<<i;
	if(t<a){
		b=t*(t+1)/2%MAX*min(x,a)%MAX;
		if(a<x)pa=calc(x-a,y-a,t);
		return make_pair((b+pa.first)%MAX,(t*min(x,a)+pa.second)%MAX);
	}
	if(a<x){
		b=a*(a+1)/2%MAX*a%MAX;
		if(t<2*a){
			b+=(t+a+1)*(t-a)/2%MAX*(x+y-2*a)%MAX;
			c=a*a+(x+y-2*a)*(t-a);
		}else{
			b+=(3*a+1)*a/2%MAX*(x+y-2*a)%MAX;
			c=(x+y-a)*a;
		}
		pa=calc(x-a,y-a,t);
		b+=pa.first;
		pa.second%=MAX;
		return make_pair(b%MAX,(c+pa.second)%MAX);
	}
	b=a*(a+1)/2%MAX*x%MAX;
	pa=calc(x,y-a,t-a);
	b+=pa.first;
	pa.second%=MAX;
	b+=a*pa.second;
	return make_pair(b%MAX,(x*a+pa.second)%MAX);
}

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c,d,e;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b>>c>>d>>e;
		s=calc(c,d,e).first-calc(a-1,d,e).first-calc(c,b-1,e).first+calc(a-1,b-1,e).first;
		if(s<0)s+=2*MAX;
		s%=MAX;
		cout<<s<<endl;
	}
}