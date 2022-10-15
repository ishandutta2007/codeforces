//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 2000

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

int T,n,mx,a[N];

string st,st1;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();mx=0;st=" ";
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=51;i++) st+='a',cout<<st[i];
		cout<<endl;
		for (int i=1;i<=n;i++)
		{
			st1=" ";
			for (int j=1;j<=a[i];j++) st1+=st[j];
			if (st[a[i]+1]+1!='z') st1+=st[a[i]+1]+1;
			else st1+=st[a[i]+1]-1;
			for (int j=a[i]+2;j<=51;j++) st1+=st[j];
			for (int j=1;j<=51;j++) cout<<st1[j];
			cout<<endl;
			st=st1;
		}
	}
}