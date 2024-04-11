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

int bit_tree[400005];
int bit_N=0;

void bit_init(int n){
	for(bit_N=1;bit_N<n;bit_N<<=1);
}
void bit_add(int a){
	int i,j;
	bit_tree[a]++;
	for(i=1;i<bit_N;i<<=1){
		if(a&i)continue;
		a+=i;
		bit_tree[a]++;
	}
}

int bit_count(int a){
	int i,j;
	int sa=0;
	sa+=bit_tree[a];
	for(i=1;i<a;i<<=1){
		if(a&i)continue;
		a-=i;
		sa+=bit_tree[a];
	}
	return sa;
}

vector<tuple<int,int,int> > v1[200005];
int pos[200005];
LL s[200005];

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c,d;
	cin>>n>>m;
	bit_init(n);
	for(i=0;i<n;i++){
		cin>>pos[i];
		pos[i]--;
	}
	for(i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		s[i]=n*(n-1)/2-a*(a-1)/2-b*(b-1)/2-(n-c-1)*(n-c-2)/2-(n-d-1)*(n-d-2)/2;
		if(a!=0){
			if(b!=0)v1[a-1].push_back(make_tuple(i,b-1,1));
			v1[a-1].push_back(make_tuple(i,d,2));
		}
		if(b!=0)v1[c].push_back(make_tuple(i,b-1,3));
		v1[c].push_back(make_tuple(i,d,4));
	}
	//array_show(s,m);
	for(i=0;i<n;i++){
		bit_add(pos[i]);
		for(auto x:v1[i]){
			tie(a,b,c)=x;
			if(b<0 || b>=n)continue;
			d=bit_count(b);
			if(c==2)d=i+1-d;
			if(c==3)d=b+1-d;
			if(c==4)d=n+d-i-b-2;
			//cout<<a<<b<<c<<d<<bit_count(b)<<endl;
			s[a]+=d*(d-1)/2;
		}
	}
	array_show(s,m,'\n');
}