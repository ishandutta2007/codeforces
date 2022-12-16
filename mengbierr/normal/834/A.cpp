#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int k,t;
int main()
{
	char x,y;
	cin>>x>>y;
	if(x=='^')
	k=0;
	else if(x=='>')
	k=1;
	else if(x=='v')
	k=2;
	else k=3;
	if(y=='^')
	t=0;
	else if(y=='>')
	t=1;
	else if(y=='v')
	t=2;
	else t=3;
	//cout<<k<<" "<<t<<endl;
	int f=read();
	f%=4;
	if((k+f)%4==t&&((k-f)%4+4)%4!=t)
	cout<<"cw";
	else if(((k-f)%4+4)%4==t&&(k+f)%4!=t)
	cout<<"ccw";
	else cout<<"undefined";
}