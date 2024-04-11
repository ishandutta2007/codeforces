#include<bits/stdc++.h>
using namespace std;
int n;
int a[5201][5201];
int x[5201];
int y[5201];
char s[4000];
int d[5201];
int b;
int main() {
	scanf("%d",&n);
	int m=n/4;
	int l;
	for(int i=0;i<n;i++) {
		scanf("%s",s);
		for(int j=0;j<m;j++) {
			if(s[j]<='9') b=s[j]-'0';
			else b=10+s[j]-'A';
			if(b>=8) {
				a[i][4*j]=1;
				b-=8;
			}
			b=b<<1;
			if(b>=8) {
				a[i][4*j+1]=1;
				b-=8;
			}
			b=b<<1;
			if(b>=8) {
				a[i][4*j+2]=1;
				b-=8;
			}
			b=b<<1;
			if(b>=8) {
				a[i][4*j+3]=1;
				b-=8;
			}
		}
	}
	/*for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d",a[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<n;i++) {
		l=1;
		m=0;
		for(int j=1;j<n;j++) {
			if(a[i][j]==a[i][j-1]) l++;
			else {
				d[m++]=l;
				l=1;
			}
		}
		d[m++]=l;
		x[i]=d[0];
		for(int j=0;j<m;j++) {
			x[i]=__gcd(x[i],d[j]);
		}
	}
	for(int i=0;i<n;i++) {
		l=1;
		m=0;
		for(int j=1;j<n;j++) {
			if(a[j][i]==a[j-1][i]) l++;
			else {
				d[m++]=l;
				l=1;
			}
		}
		d[m++]=l;
		y[i]=d[0];
		for(int j=0;j<m;j++) {
			y[i]=__gcd(y[i],d[j]);
		}
	}
	l=x[0];
	for(int i=0;i<n;i++) {
		l=__gcd(l,x[i]);
		l=__gcd(l,y[i]);
	}
	printf("%d",l);
	return 0;
}