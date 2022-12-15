#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<ctime> 
#define LL long long 
using namespace std;
const int N=1e5+10;
LL l,r,m,x,y,A,B,C,D,n;
int main(){
	int T;scanf("%d",&T);
	LL z,a,b;
	while(T--){
		scanf("%I64d%I64d%I64d",&l,&r,&m);
		y=m+r-l;x=m-r+l-1;x=max(x,(LL)0);
		for(LL i=l;i<=min(r,y);){
			z=y/i-x/i;
			if(z){
				A=i;
				n=y/i;
				D=A*n-m;
				if(D>0){
					B=l;
					C=l+D;
				}
				else{
					B=r;
					C=r+D;
				}
				cout<<A<<" "<<B<<" "<<C<<endl;
				break;
			}
			else{
				a=y/(y/i)+1;
				b=x/(x/i)+1;
				if(a<b) i=a;
				else i=b;
			}
		}
	}
	return 0;
}