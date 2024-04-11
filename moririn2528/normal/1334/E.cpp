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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

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

long long int gcd(long long int g_a,long long int g_b){
	if(g_a<g_b)gcd(g_b,g_a);
	if(g_b==0)return g_a;
	return gcd(g_b,g_a%g_b);
}

long long int divide(long long int d_a,long long int d_b,long long int d_p=1e9+7){
	// d_a/d_b mod d_p
	// prime:d_p is prime
	if(d_a>=d_p)d_a%=d_p;
	if(d_a<0)d_a+=d_p;
	if(d_b>=d_p)d_b%=d_p;
	if(d_b<0)d_b+=d_p;
	d_a*=pow_mod(d_b,d_p-2,d_p);
	return d_a%d_p;
}

vector<P> prim;
LL kai[150];

LL check(LL x,LL y){
	LL s=1;
	LL a,b,c;
	LL cnt=0;
	for(auto node:prim){
		a=node.first;
		b=0,c=0;
		while(x%a==0)b++,x/=a;
		while(y%a==0)c++,y/=a;
		b=abs(b-c);
		if(b){
			cnt+=b;
			s=divide(s,kai[b],MAX);
		}
	}
	s*=kai[cnt];
	s%=MAX;
	return s;
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	kai[0]=1;
	for(i=1;i<100;i++){
		kai[i]=kai[i-1]*i;
		if(kai[i]>=MAX)kai[i]%=MAX;
	}
	scanf("%lld%lld",&n,&m);
	a=sqrt(n);
	for(i=2;i<=a;i++){
		if(n==1)break;
		b=0;
		while(n%i==0)b++,n/=i;
		if(b)prim.push_back(make_pair(i,b));
	}
	if(n!=1)prim.push_back(make_pair(n,1));
	LL x,y;
	for(i=0;i<m;i++){
		scanf("%lld%lld",&x,&y);
		a=gcd(x,y);
		a=check(x,a)*check(y,a);
		a%=MAX;
		printf("%lld\n",a);
	}
}