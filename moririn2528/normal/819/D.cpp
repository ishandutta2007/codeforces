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

vector<LL> v1;
vector<tuple<LL,LL,LL> > v2;
LL s[220000];
LL bef[220000][2];

map<LL,LL> m1;

LL gcd(LL a,LL b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return gcd(b,a%b);
}

typedef long long int d2_type;
typedef pair<d2_type,d2_type> d2_pair_type;
d2_pair_type ext_gcd(d2_type d2_a,d2_type d2_b,d2_type d2_bef2,d2_type d2_bef,d2_type d2_mod){
	// define a >= b
	if(d2_a % d2_b == 0)return make_pair(d2_b,d2_bef);
	d2_type d2_t=d2_bef2-d2_a/d2_b*d2_bef;
	if(d2_t<0)d2_t+=((-d2_t-1)/d2_mod+1)*d2_mod;
	else if(d2_t>=d2_mod)d2_t%=d2_mod;
	return ext_gcd(d2_b,d2_a%d2_b,d2_bef,d2_t,d2_mod);
}

d2_type divide2(d2_type d2_a,d2_type d2_b,d2_type d2_p=1e9+7){
	// a/b mod p (good for prime or not)  O(log p)
	if(d2_a>=d2_p)d2_a%=d2_p;
	if(d2_a<0)d2_a+=d2_p;
	if(d2_b>=d2_p)d2_b%=d2_p;
	if(d2_b<0)d2_b+=d2_p;
	if(d2_a==0)return 0;
	if(d2_b==0)return -1;
	d2_pair_type d2_pa=ext_gcd(d2_p,d2_b,0,1,d2_p);
	if(d2_a%d2_pa.first)return -1;
	d2_type d2_s=d2_a/d2_pa.first*d2_pa.second;
	d2_s%=d2_p;
	return d2_s;
}

int main(){
	LL n,m,p;
	LL i,j,k;
	LL a,b,c;
	b=0;
	cin>>m>>n;
	for(i=0;i<n;i++){
		cin>>a;
		b+=a;
		if(b>=m)b-=m;
		v1.push_back(b);
	}
	a=gcd(b,m);
	LL x,y,z;
	for(i=0;i<n;i++){
		y=v1[i]%a;
		v1[i]/=a;
		if(m1.find(y)==m1.end())m1[y]=m1.size();
		y=m1[y];
		x=divide2(v1[i],b/a,m/a);
		v2.push_back(make_tuple(x,y,i));
	}
	sort(v2.begin(),v2.end());

	memset(bef,-1,sizeof(bef));
	for(auto node:v2){
		tie(x,y,z)=node;
		c=bef[y][1];
		if(x==bef[y][0] && bef[y][1]!=z)continue;

		bef[y][0]=x,bef[y][1]=z;
	}
	for(auto node:v2){
		tie(x,y,z)=node;
		c=bef[y][1];
		#ifdef MORIRIN
		cout<<x<<" "<<y<<" "<<z<<endl;
		cout<<c<<endl;
		#endif //MORIRIN
		if(x==bef[y][0] && bef[y][1]!=z)continue;

		s[c]=x-bef[y][0];
		if(s[c]<0)s[c]+=m/a;
		if(bef[y][1]==z)s[c]=m/a;
		bef[y][0]=x,bef[y][1]=z;
	}
	array_show(s,n);
}