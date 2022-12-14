#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define mo 1000000007
#define N 1099
int n,k,rec[N];
int main(){
	scanf("%d",&n);
	rpt(i,0,n-1) rec[i]=1000000000;
	rpt(i,0,9) rpt(t,0,1){
		k=0;
		rpt(j,0,n-1) if(((j>>i)&1)==t) k++;
		if(k){
			printf("%d\n",k);
			rpt(j,0,n-1) if(((j>>i)&1)==t) printf("%d ",j+1);
			printf("\n");
			fflush(stdout);
			rpt(j,0,n-1){
				scanf("%d",&k);
				if(((j>>i)&1)==1-t) if(k<rec[j]) rec[j]=k;
			}
		}
	}
	printf("-1\n");
	rpt(i,0,n-1) printf("%d ",rec[i]);
	fflush(stdout);
}