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

void init(){
	
}

void solve(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	vector<LL> v1;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&a);
		v1.push_back(a);
	}
	if(m==1){
		cout<<n%2<<endl;
		return;
	}
	sort(v1.rbegin(),v1.rend());
	a=0,b=v1[0];
	for(i=0;i<n;i++){
		if(a==0)b=v1[i];
		while(b>v1[i]){
			b--;
			a*=m;
			if(a>=n)break;
		}
		if(b>v1[i] || a>=n)break;
		a--;
		if(a<0)a+=2;
	}
	a%=MAX;
	a*=pow_mod(m,b);
	a%=MAX;
	for(c=0;i<n;i++){
		c+=pow_mod(m,v1[i]);
	}
	c%=MAX;
	a-=c;
	if(a<0)a+=MAX;
	printf("%lld\n",a);
}

int main(){
	int n,i;
	init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		solve();
	}
}