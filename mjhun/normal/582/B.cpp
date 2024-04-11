#include <bits/stdc++.h>
using namespace std;

int x[20005];
int p[20005];
int m[20005];
int nx;

int lnds(){
	int l=0;
	for(int i=0;i<nx;++i){
		int lo=1,hi=l;
		while(lo<=hi){
			int mid=(lo+hi+1)/2;
			if(x[m[mid]]<=x[i])lo=mid+1;
			else hi=mid-1;
		}
		p[i]=m[lo-1];
		m[lo]=i;
		l=max(l,lo);
	}
	return l;
}


int q[512];
int n,t;

int main(){
	scanf("%d%d",&n,&t);
	nx=min(n+1,t);
	for(int i=0;i<n;++i){
		scanf("%d",x+i);
		q[x[i]]++;
		for(int j=1;j<nx;++j){
			x[i+j*n]=x[i];
		}
	}
	nx*=n;
	int mq=0;
	for(int i=1;i<=300;++i){
		mq=max(mq,q[i]);
	}
	printf("%d\n",lnds()+(t-min(n+1,t))*mq);
	return 0;
}