#include<bits/stdc++.h>
using namespace std;
long long n;
int m=0;
int a[500000];
int b[500000];
long long t1,t2;
int main()
{
	scanf("%d",&n);
	if(n<=100) {
		a[0]=1;
		for(int i=1;i<=n;i++) {
			for(int j=50*(i-1);j>=i-1;j--) {
				if(a[j]>0) {
					b[j+1]=1;
					b[j+5]=1;
					b[j+10]=1;
					b[j+50]=1;
					a[j]=0;
				}
			}
			for(int j=50*i;j>=i;j--) {
				a[j]=b[j];
				b[j]=0;
			}
		}
		int t=0;
		for(int j=n;j<=50*n;j++) {
			if(a[j]>0) t++;
		}
		printf("%d",t);
	}
	else {
		a[0]=1;
		for(int i=1;i<=100;i++) {
			for(int j=50*(i-1);j>=i-1;j--) {
				if(a[j]>0) {
					b[j+1]=1;
					b[j+5]=1;
					b[j+10]=1;
					b[j+50]=1;
					a[j]=0;
				}
			}
			for(int j=50*i;j>=i;j--) {
				a[j]=b[j];
				b[j]=0;
			}
			//cout<<i<<" "<<endl;
			if(i==99) {
				for(int j=i;j<=50*i;j++) {
					//cout<<j<<endl;
					if(a[j]>0) {
						t1++;
						//cout<<j<<endl;
					}
				}
			}
			if(i==100) {
				for(int j=i;j<=50*i;j++) {
					if(a[j]>0) t2++;
				}
			}
			//cout<<i<<" "<<t1<<" "<<t2<<endl;
		}
		//cout<<t1<<" "<<t2<<endl;
		long long dt=t2-t1;
		printf("%lld",(n-100)*dt+t2);
	}
	return 0;
}