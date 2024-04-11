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

LL seed,n,m,vmax;
LL t[100005];

LL rnd(){
    LL ret = seed;
    seed = (seed * 7 + 13) % MAX;
    return ret;
}

void init(){
	for(int i=0;i<n;i++){
		t[i]=(rnd() % vmax) + 1;
	}
}

LL op,l,r,x,y;

void load(){
    op = (rnd() % 4) + 1;
    l = (rnd() % n);
    r = (rnd() % n);

    if (l > r)swap(l, r);

    if (op == 3)x = (rnd() % (r - l + 1)) + 1;
    else x = (rnd() % vmax) + 1;
    if (op == 4)y = (rnd() % vmax) + 1;
}

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=1e9+7){
	//p_a^p_n mod p_p
	if(p_a>=p_p)p_a%=p_p;
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

map<LL,LL> m1;
vector<pair<LL,LL> > v1;

int main(){
	int i,j,k;
	LL a,b,c;
	LL s=0;
	k=0;
	cin>>n>>m>>seed>>vmax;
	init();

	//array_show(t,n);

	for(i=0;i<n;i++){
		m1[i]=t[i];
	}
	m1[n+1]=-1;
	auto itr=m1.begin();
	for(i=0;i<m;i++){
		load();
		LL ss[10]={i,op,l,r,x,y};
		//array_show(ss,6);
		if(op==1){
			itr=m1.upper_bound(l);
			itr--;
			a=itr->second;
			m1[l]=itr->second + x;
			itr=m1.upper_bound(l);
			for(;(itr->first)<=r;itr++){
				a=itr->second;
				b=itr->first;
				m1[b]+=x;
			}
			if((itr->first)!=r+1)m1[r+1]=a;
		}
		if(op==2){
			itr=m1.upper_bound(r+1);
			itr--;
			m1[r+1]=itr->second;
			m1[l]=x;
			while(1){
				itr=m1.upper_bound(l);
				if((itr->first)>r)break;
				m1.erase(itr);
			}
		}
		if(op==3){
			v1.clear();
			itr=m1.upper_bound(l);
			itr--;
			for(;(itr->first)<=r;){
				a=max(itr->first,l);
				c=itr->second;
				itr++;
				b=min(itr->first,r+1);
				v1.push_back(make_pair(c,b-a));
			}
			sort(v1.begin(),v1.end());
			a=0;
			for(auto node:v1){
				a+=node.second;
				b=node.first;
				if(a>=x)break;
			}
			cout<<b<<endl;
			k++;
		}
		if(op==4){
			itr=m1.upper_bound(l);
			itr--;
			s=0;
			for(;(itr->first)<=r;){
				a=max(itr->first,l);
				c=itr->second;
				//cout<<c<<endl;
				itr++;
				b=min(itr->first,r+1);
				c=pow_mod(c,x,y);
				s+=c*(b-a);
				if(s>=y)s%=y;
			}
			cout<<s<<endl;
			k++;
		}
		//cout<<"WW"<<endl;
		//for(auto node:m1)cout<<node.first<<" "<<node.second<<endl;
	}
}