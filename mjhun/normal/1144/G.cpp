#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int n;
int a[200005];
int f0[200005]; // inc -> max dec
int f1[200005]; // dec -> min inc
int c0[200005],c1[200005]; // que hice con el anterior
int r[200005];

#define INF (1<<30)

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	f0[0]=INF;f1[0]=-INF;
	fore(i,1,n){
		f0[i]=-INF;
		if(a[i]>a[i-1])f0[i]=f0[i-1],c0[i]=0;
		if(a[i]>f1[i-1]&&a[i-1]>f0[i])f0[i]=a[i-1],c0[i]=1;
			
		f1[i]=INF;
		if(a[i]<a[i-1])f1[i]=f1[i-1],c1[i]=1;
		if(a[i]<f0[i-1]&&a[i-1]<f1[i])f1[i]=a[i-1],c1[i]=0;
	}
	if(f0[n-1]==-INF&&f1[n-1]==INF){
		puts("NO");
		return 0;
	}
	puts("YES");
	int t=0,k=n-1;
	if(f1[n-1]<INF)t=1;
	while(k>=0){
		r[k]=t;
		if(t==0)t=c0[k];
		else t=c1[k];
		k--;
	}
	fore(i,0,n)printf("%d%c",r[i]," \n"[i==n-1]);
	return 0;
}