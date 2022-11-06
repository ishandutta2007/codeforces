//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,x,y,a[10],bl,ans;

signed main()
{
	T=read();
	while (T--)
	{
		x=read(),y=read();ans=0;
		a[0]=read(),a[1]=read(),a[2]=read(),a[3]=read(),a[4]=read(),a[5]=read();
		for (int i=1;i;i++)
		{
			bl=1;
			for (int j=0;j<=5;j++)
			  if (a[(j-1+6)%6]+a[(j+1)%6]<a[j]) 
			  {
			  	a[j]=a[(j-1+6)%6]+a[(j+1)%6];
			  	bl=0;
			  }
			if (bl) break;
			//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
		}
		if (x>0&&y>0)
		{
			ans+=min(x,y)*a[0]+max(y-x,0ll)*a[1]+max(x-y,0ll)*a[5];
		}
		if (x<0&&y>0)
		{
			ans+=abs(x)*a[2]+abs(y)*a[1];
		}
		if (x>0&&y<0)
		{
			ans+=abs(x)*a[5]+abs(y)*a[4];
		}
		if (x<0&&y<0)
		{
			ans+=min(abs(x),abs(y))*a[3]+max(y-x,0ll)*a[2]+max(x-y,0ll)*a[4];
		}
		if (x==0&&y<0) ans+=a[4]*abs(y);
		if (y==0&&x<0) ans+=a[2]*abs(x);
		if (x==0&&y>0) ans+=a[1]*abs(y);
		if (y==0&&x>0) ans+=a[5]*abs(x);
		writeln(ans);
	}		
}
/*
10000
0 -9
16 7 12 26 25 30
5 -28
16 18 16 8 11 21
-1 4
12 18 27 8 30 27
-24 -14
4 1 24 27 13 1
17 -5
8 13 11 20 1 28
-10 -12
26 3 30 1 4 2
7 -1
28 17 20 21 15 4
-26 -1
20 7 17 9 11 15
-15 23
17 21 3 3 20 26
30 -25
27 3 19 20 11 30
18 1
29 8 16 21 28 10
28 -6
8 30 6 4 2 19
11 7
22 8 25 17 11 19
4 -27
3 6 10 30 22 5
-24 -14
9 21 21 20 9 18
23 -25
16 16 4 4 3 1
-9 -30
12 21 6 1 5 13
26 4
3 3 27 10 19 25
5 -28
8 2 1 14 22 10
-21 7
16 21 7 2 2 18
*/