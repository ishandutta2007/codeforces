#include<bits/stdc++.h>
using namespace std;
int inf=1e9;
int n;
int k;
int a[5002];
int s[5002][2502];
int o[3][2502];
int t[2502];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	k=(n+1)/2;
	int b;
	for(int i=1;i<=k;i++) o[0][i]=o[1][i]=o[2][i]=inf;
	for(int i=0;i<n;i++) {
		//Ako ne gradim kucu - nista
		for(int j=0;j<=k;j++) t[j]=inf;
		t[0]=0;
		//Ako gradim ovde kucu i izgradio sam je pre tacno dva mesta.
		b=0;
		if(i>1) {
			if(a[i]<=min(a[i-1],a[i-2]-1)) b=min(a[i-1],a[i-2]-1)-a[i]+1; 
		}
		else {
			if(i>0 && a[i]<=a[i-1]) b=a[i-1]-a[i]+1;
		}
		if(a[i+1]>=a[i]) b+=(a[i+1]-a[i]+1);
		for(int j=2;j<=k;j++) t[j]=min(t[j],o[1][j-1]+b);
		//Ako gradim ovde i izgradio sam je "davno" ranije
		b=0;
		if(i>0) {
			if(a[i]<=a[i-1]) b=a[i-1]-a[i]+1; 
		}
		if(a[i+1]>=a[i]) b+=(a[i+1]-a[i]+1);
		for(int j=1;j<=k;j++) t[j]=min(t[j],o[2][j-1]+b);
		for(int j=0;j<=k;j++) {
			o[2][j]=min(o[2][j],o[1][j]);
			o[1][j]=o[0][j];
			o[0][j]=t[j];
			//cout<<t[j]<<endl;
		}
	}
	for(int j=0;j<=k;j++) t[j]=min(o[0][j],min(o[1][j],o[2][j]));
	for(int i=1;i<=k;i++) printf("%d ",t[i]);
	return 0;
}