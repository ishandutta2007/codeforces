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

int T,n,m,bl,x1,x2,bl1;

signed main()
{
	T=read();
	while (T--)
	{
		n=read(),m=read();bl=bl1=0;
		if (m&1) 
		{
			puts("NO");
			bl1=1;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=2;j++)
			{
				cin>>x1;
				if (j==2) 
				{
					if (x1==x2) bl=1;
				}
				cin>>x2;
			}
		}
		if (bl&&!bl1) cout<<"YES"<<endl; else if (!bl1)cout<<"NO"<<endl;
	}
}