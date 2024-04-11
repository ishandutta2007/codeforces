#include<bits/stdc++.h>
using namespace std;
int n;
bool fb;
bool ab=true;
bool aw=true;
char s[10];
int x=5e8-1,y=0;
int t[2][2];
bool c[100];
int xc[100],yc[100];
void separate(int i,int j) {
	double a1,a2;
	a1=xc[i]+xc[j];
	a1/=2.00;
	a2=yc[i]+yc[j];
	a2/=2.00;
	double b1,b2;
	b1=t[0][0];
	b2=t[0][1];
	double c1,c2;
	c1=a1-b1;
	c2=a2-b2;
	a1=b1+2.00*c1;
	a2=b2+2.00*c2;
	t[1][0]=a1;
	t[1][1]=a2;
}
int main()
{
	scanf("%d",&n);
	t[0][0]=5e8;
	t[0][1]=0;
	t[1][0]=5e8;
	t[1][1]=1;
	xc[0]=x;
	yc[0]=y;
	xc[99]=x+2;
	yc[99]=y;
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='w') c[0]=false;
	else c[0]=true;
	int oc=99;
	for(int i=1;i<n;i++) {
		//x=t[1][0];
		//y=t[1][1];
		xc[i]=t[1][0];
		yc[i]=t[1][1];
		printf("%d %d\n",t[1][0],t[1][1]);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='w') c[i]=false;
		else c[i]=true;
		if(c[i]!=c[i-1]) {
			separate(i,i-1);
			oc=i-1;
		}
		else separate(i,oc);
	}
	printf("%d %d %d %d\n",t[0][0],t[0][1],t[1][0],t[1][1]);
	fflush(stdout);
	return 0;
}