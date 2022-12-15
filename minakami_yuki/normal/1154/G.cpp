#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=1e7+10;
const LL inf=1e15;
int n;
int a[N][2],A,B;
LL ans=inf;
LL b[1000005];
int l,r;
int main(){
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);b[i]=x;
		if(a[x][0]==0) a[x][0]=i;
		else a[x][1]=i;
	}
	for(int i=1;i<=10000000;++i){
		if(i>=ans) break;
		A=0;B=0;
		for(int j=i;j<=10000000;j+=i){
			if(a[j][0]){
				if(!A) A=a[j][0];
				else{
					B=a[j][0];break;
				}
			}
			if(a[j][1]){
				if(!A) A=a[j][1];
				else{
					B=a[j][1];break;
				}
			}
		}
		if(A&&B&&ans>b[A]/(LL)i*b[B]){
			ans=b[A]/(LL)i*b[B];
			l=A;r=B;
		}
	
	}
	if(l>r) swap(l,r);
	printf("%d %d\n",l,r);
	return 0;
}