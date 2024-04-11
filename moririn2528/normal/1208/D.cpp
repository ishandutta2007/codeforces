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
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

LL t[400005];
LL N;
LL q[200005];

void add_tree(LL x,LL p){
	if(x>N || x<=0)return;
	t[x]+=p;
	for(int i=0;;i++){
		if(x&(1<<i)){
			x+=(1<<i);
			break;
		}
	}
	add_tree(x,p);
}

int check(LL x,LL p){
	LL a;
	LL i;
	if(x==0)return 0;
	if(x%2==1){
		if(t[x]==p)return x;
		return x-1;
	}
	if(t[x]>p){
		for(i=0;;i++){
			if(x&(1<<i)){
				x-=(1<<(i-1));
				break;
			}
		}
		return check(x,p);
	}
	p-=t[x];
	for(i=0;;i++){
		if(x&(1<<i)){
			x+=(1<<(i-1));
			break;
		}
	}
	return check(x,p);
}
	

int main(){
	LL n;
	int i,j,k;
	LL a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>q[i];
	}
	for(a=1;a<=n;a<<=1);
	N=a;
	for(i=1;i<=a;i++){
		add_tree(i,i);
	}
	for(i=n-1;i>=0;i--){
		a=check(N,q[i]);
		add_tree(a+1,-a-1);
		q[i]=a+1;
	}
	array_show(q,n);
}