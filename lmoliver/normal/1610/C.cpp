#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=2.1e5;
int a[N],b[N];
int l[N],r[N];

bool test(int n,int k){
	F(i,1,n){
		l[i]=max(1,k-a[i]);
		r[i]=min(k,b[i]+1);
	}
	int cur=0;
	F(i,1,n){
		if(cur+1>=l[i]&&cur+1<=r[i]&&++cur>=k)return true;
	}
	return false;
}

void work(){
	int n=read();
	F(i,1,n){
		a[i]=read();
		b[i]=read();
	}
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(test(n,mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",l);
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}