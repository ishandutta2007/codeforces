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
typedef pair<int,int> P;
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

int t[220000];
LL kai[220000];
LL rui[2][220000];//m,m-2

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

long long int divide(long long int d_a,long long int d_b,long long int d_p=1e9+7,bool prime=true){
	// d_a/d_b mod d_p
	// prime:d_p is prime or not
	if(d_a>=d_p)d_a%=d_p;
	if(d_a<0)d_a+=d_p;
	if(d_b>=d_p)d_b%=d_p;
	if(d_b<0)d_b+=d_p;
	if(!prime){
		long long int d_d=gcd(d_a,d_b);
		if(d_d>1)d_a/=d_d,d_b/=d_d;
	}
	d_a*=pow_mod(d_b,d_p-2,d_p);
	return d_a%d_p;
}

int main(){
	LL n,m;
	LL i,j,k;
	LL a,b,c;
	LL co=0;
	LL s=0;
	cin>>n>>m;
	if(m==1){
		cout<<0<<endl;
		return 0;
	}
	kai[0]=1,kai[1]=1;
	for(i=2;i<=n;i++){
		kai[i]=kai[i-1]*i;
		if(kai[i]>=MAX)kai[i]%=MAX;
	}
	a=m;
	for(i=0;i<2;i++,a-=2){
		rui[i][0]=1;
		if(a==0)continue;
		for(j=1;j<=n;j++){
			rui[i][j]=rui[i][j-1]*a;
			if(rui[i][j]>=MAX)rui[i][j]%=MAX;
		}
	}
	for(i=0;i<n;i++){
		cin>>t[i];
	}
	for(i=0;i<n;i++){
		j=(i+1)%n;
		if(t[i]!=t[j])co++;
	}
	for(i=0;i*2<=co;i++){
		a=kai[co-2*i]*(kai[i]*kai[i]%MAX)%MAX;
		a=divide(kai[co],a,MAX);
		//cout<<a<<" ";
		a=a*rui[0][n-co]%MAX;
		//cout<<a<<" ";
		a=a*rui[1][co-2*i]%MAX;
		//cout<<a<<" ";
		s+=a;
		if(s>=MAX)s-=MAX;
		//cout<<s<<endl;
	}
	s=rui[0][n]-s;
	if(s<0)s+=MAX;
	s=divide(s,2,MAX);
	cout<<s<<endl;
}