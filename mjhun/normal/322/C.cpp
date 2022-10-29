#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int m[105][2];
int abs(int a){
	return((a>0)?a:-a);
}
int sgn(int a){
	if(a>0)
		return 1;
	if(a<0)
		return -1;
	return 0;
}
bool succ(int a, int b, int x, int y){
	if(a==0&&b==0)
		return true;
	if(sgn(a)!=sgn(x)||sgn(b)!=sgn(y))
		return false;
	if(x==0&&y==0)
		return (a==0&&b==0);
	if(x==0)
		return (a==0&&b%y==0);
	if(y==0)
		return (b==0&&a%x==0);
	
	a=abs(a);
	b=abs(b);
	x=abs(x);
	y=abs(y);
	return((a%x==0)&&(b%y==0)&&(a/x==b/y));
}
int main(){
	int x=0,y=0,a,b,i,n;
	char s[105];
	bool bl=false;
	cin>>a>>b;
	scanf("%s",s);
	m[0][0]=0;
	m[0][1]=0;
	n = strlen(s);
	for(i=0;i<n;++i){
		switch(s[i]){
			case 'U':
				++y;
				break;
			case 'D':
				--y;
				break;
			case 'L':
				--x;
				break;
			case 'R':
				++x;
				break;
		}
		m[i+1][0]=x;
		m[i+1][1]=y;
	}
	i=0;
	while(!bl&&i<n){
		bl=succ(a-m[i][0],b-m[i][1],x,y);
		++i;
	}
	cout<<(bl?"Yes":"No")<<endl;
	return 0;
}