#include <cstdio>
#include <iostream>
#define gc getchar
using namespace std;
int md[]={0,31,59,90,120,151,181,212,243,273,304,334,365};

int leap(int y,int m){
	int r;
	r = (y-1)/4-(y-1)/100+(y-1)/400;
	if(y%4==0&&(y%100!=0||y%400==0)&&m>2)
		++r;
	return r;
}

int main(){
	int y1,m1,d1,y2,m2,d2,r1,r2,r;
	cin>>y1;gc();cin>>m1;gc();cin>>d1;
	cin>>y2;gc();cin>>m2;gc();cin>>d2;
	r1=y1*365+md[m1-1]+d1+leap(y1,m1);
	r2=y2*365+md[m2-1]+d2+leap(y2,m2);
	r=r1-r2;
	if(r<0)
		r=-r;
	cout<<r<<endl;
	return 0;
}