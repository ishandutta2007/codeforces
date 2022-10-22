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

typedef int seg_type;// change type
const int N=2e5+7;
int seg_N;
seg_type seg[N*4];

seg_type seg_func(seg_type seg_a,seg_type seg_b){
	return seg_a+seg_b;// function
}

void seg_init(int seg_n){
	int seg_i;
	for(seg_i=0;(1<<seg_i)<seg_n;seg_i++);
	seg_N=(1<<seg_i)-1;
}

void seg_init_reload(){
	for(int seg_i=seg_N-1;seg_i>=0;seg_i--){
		seg[seg_i]=seg_func(seg[2*seg_i+1],seg[2*seg_i+2]);
	}
}

void seg_init(seg_type *seg_t,int seg_n){
	seg_init(seg_n);
	for(int seg_i=0;seg_i<seg_n;seg_i++){
		seg[seg_N+seg_i]=seg_t[seg_i];
	}
	seg_init_reload();
}

void seg_init(seg_type seg_a,int seg_n){
	seg_init(seg_n);
	for(int seg_i=0;seg_i<seg_n;seg_i++){
		seg[seg_N+seg_i]=seg_a;
	}
	seg_init_reload();
}

void seg_update(int seg_pos){
	seg_type seg_a=seg_func(seg[seg_pos*2+1],seg[seg_pos*2+2]);
	if(seg[seg_pos]==seg_a)return;
	seg[seg_pos]=seg_a;
	if(seg_pos==0)return;
	seg_update((seg_pos-1)/2);
}

void seg_set(int seg_pos,seg_type seg_a){
	seg_pos+=seg_N;
	seg[seg_pos]=seg_a;
	seg_update((seg_pos-1)/2);
}

seg_type seg_search(int num,int seg_x=0){//[a,b) search
	if(seg_x>=seg_N)return seg_x-seg_N;
	int a=seg[seg_x*2+1];
	if(a<num){
		num-=a;
		return seg_search(num,seg_x*2+2);
	}
	return seg_search(num,seg_x*2+1);
}

vector<P> v1;
vector<tuple<int,int,int> > v2;
int t[200005];
int s[200005];

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int x,y,z;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v1.push_back(make_pair(-a,i));
		t[i]=a;
	}
	sort(v1.begin(),v1.end());
	cin>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		v2.push_back(make_tuple(a,b,i));
	}
	sort(v2.begin(),v2.end());
	a=0;
	seg_init(n);
	for(i=0;i<m;i++){
		tie(x,y,z)=v2[i];
		for(;a<x;a++){
			b=v1[a].second;
			seg_set(b,1);
		}
		c=seg_search(y);
		s[z]=t[c];
	}
	array_show(s,m,'\n');
}