#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n;
int a[1024],b[1024];
int sa[1024],sb[1024];

int main(){
	scanf("%d",&n);
	int r0=0,r1=0;
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		r0|=a[i];
	}
	for(int i=0;i<n;++i){
		scanf("%d",b+i);
		r1|=b[i];
	}
	int r=r0+r1;/*
	for(int i=0;i<n;++i){
		for(int j=i+1;j<=n;++j){
			r=max(r,(sa[j]^sa[i])+(sb[j]^sb[i]));
		}
	}*/
	printf("%d\n",r);
	return 0;
}