#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[1<<18];
int b[1<<18];
int sa[18][1<<18];
int sb[18][1<<18];
int n;

void inita(){
	for(int i=0;i<n;++i)sa[0][i]=a[i];
	for(int k=1;(1<<k)<=n;++k)
		for(int i=0;i<n;++i)
			sa[k][i]=max(sa[k-1][i],sa[k-1][i+(1<<(k-1))]);
}

void initb(){
	for(int i=0;i<n;++i)sb[0][i]=b[i];
	for(int k=1;(1<<k)<=n;++k)
		for(int i=0;i<n;++i)
			sb[k][i]=min(sb[k-1][i],sb[k-1][i+(1<<(k-1))]);
}

int querya(int s, int e){
	if(s==e)return -(1<<30);
	int k=31-__builtin_clz(e-s);
	return max(sa[k][s],sa[k][e-(1<<k)]);
}

int queryb(int s, int e){
	if(s==e)return 1<<30;
	int k=31-__builtin_clz(e-s);
	return min(sb[k][s],sb[k][e-(1<<k)]);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<n;++i)scanf("%d",b+i);
	inita();
	initb();
	ll r=0;
	for(int i=0;i<n;++i){
		int s=i,e=n+1;
		while(e-s>1){
			int m=(s+e)/2;
			if(querya(i,m)<queryb(i,m))s=m;
			else e=m;
		}
		int f=s;
		s=i,e=n+1;
		while(e-s>1){
			int m=(s+e)/2;
			if(querya(i,m)<=queryb(i,m))s=m;
			else e=m;
		}
		r+=e-f-1;
	}
	cout<<r<<endl;
	return 0;
}