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
int T,n,x,y,xx,p,pp,bl;
signed main()
{
    T=read();
    while (T--)
    {
    	n=read(),x=read(),y=read();bl=0;
    	for (int j=n;j>=1;j--)
    	{if (bl) break;
    	  for (int i=j-1;i>=1;i--)
    	  {//cout<<i<<" "<<j<<"!"<<endl;
    	  	if (bl) break;
    	  	if ((y-x)%(j-i)==0) 
    	  	{
    	  		pp=(y-x)/(j-i);
    	  		if (x/pp<(i-1)) continue;
    	  		x-=pp*(i-1);
    	  		if (x==0) {x+=pp*(i-1);continue;}
    	  		for (int k=1;k<=n;k++)
    	  		  writesp(x),x+=pp;
    	  		bl=1;
    	  		break;
    	  	}
    	  }}
    	  printf("\n");
    }
}
/*
20 26 32 38 44 50
*/