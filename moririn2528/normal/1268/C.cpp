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


typedef int bit_type;
vector<bit_type> bit_vec;
int bit_N=20;

bit_type bit_comp(bit_type a,bit_type b){
	return a+b;
}

void bit_init(int n){
	for(bit_N=0;bit_N<30;bit_N++){
		if(n<(1<<bit_N))break;
	}
	bit_vec.assign((1<<bit_N),0);
}

void bit_set(int pos,bit_type x){
	bit_vec[pos]=bit_comp(bit_vec[pos],x);
	for(int i=0;i<bit_N;i++){
		if(pos&(1<<i))continue;
		pos|=(1<<i);
		bit_vec[pos]=bit_comp(bit_vec[pos],x);
	}
}

bit_type bit_search(int pos){
	bit_type s=bit_vec[pos];
	for(int i=0;pos>=(1<<i);i++){
		if(pos&(1<<i))continue;
		pos-=(1<<i);
		s=bit_comp(s,bit_vec[pos]);
	}
	return s;
}

int po[200005];
int t[200005];
vector<LL> vs;
map<int,int> m1;

int main(){
	int n,m;
	int i,j,k;
	LL a,b,c;
	scanf("%d",&n);
	bit_init(n);
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
		t[i]--;
		po[t[i]]=i;
	}
	vs.push_back(0);
	bit_set(po[0],1);
	int cen=po[0];
	LL cnt=0,ab=0;
	m1[po[0]]=0;
	for(i=1;i<n;i++){
		a=bit_search(po[i]);
		c=a;
		a=i-a;
		ab+=a;
		bit_set(po[i],1),c++;
		m1[po[i]]=i;
		if(po[i]<cen){
			b=bit_search(cen)-c;
			b=cen-po[i]-b;
			cnt+=b;
			cnt-=bit_search(po[i])-1;
			auto itr=m1.find(cen);
			b=bit_search(cen)-1;
			if(b*2>i+1){
				b=2*b-i-1,itr--;
				cnt-=b*(cen-itr->first-1);
				cen=itr->first;
			}
		}else{
			b=c-bit_search(cen);
			b=po[i]-cen-b;
			cnt+=b;
			cnt-=i+1-bit_search(po[i]);
			auto itr=m1.find(cen);
			b=bit_search(cen)-1;
			if(b*2<i-1){
				b=i-2*b-1,itr++;
				cnt-=b*(itr->first-cen-1);
				cen=itr->first;
			}
		}
		vs.push_back(ab+cnt);
	}
	array_show(vs);
}