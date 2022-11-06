//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

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

int T,n,ans,r,l;

string a;

signed main()
{
	T=read();
	while (T--)
	{
		ans=l=r=0;
		cin>>a;
		n=a.length();
		a=' '+a+' ';
		for (int i=n;i>=1;i--)
		  if (a[i]=='B') l++; else if (l) l--; else ans++;
		writeln(ans+(l&1));
	}
		
}