#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define y0 y_0
#define y1 y_1
#define yn y_n
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,a[200005],d[400005],r[400005];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n-1;i++)d[i]=a[i+1]-a[i];
	for(int i=n*2-2;i>=0;i--){
		d[i]=(i%2==1?d[i/2]:-1);
//		printf(" %d",d[i]);
	}
//	printf("\n");
	int p=-1,rb=-1;
	for(int i=0;i<=n*2-2;i++){
		if(i<=rb)r[i]=min(r[2*p-i],rb-i);
		else r[i]=0;
		while(i-r[i]-1>=0&&i+r[i]+1<=2*n&&d[i-r[i]-1]==d[i+r[i]+1])r[i]++;
		if(i+r[i]>rb)p=i,rb=i+r[i];
//		printf(" %d",r[i]);
	}
//	printf("\n");
	vector<int> res;
	for(int i=0;i<n-1;i++){
		int lsum=a[0]+a[i],rsum=a[i+1]+a[n-1]-m;
		if(lsum==rsum&&r[i]>=i&&r[i+n]>=n-2-i)res.push_back(lsum);
	}
	if(r[n-1]==n-1)res.push_back((a[0]+a[n-1])%m);
	sort(res.begin(),res.end());
	printf("%d\n",int(res.size()));
	if(!res.empty()){
		for(size_t i=0;i<res.size();i++)printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}