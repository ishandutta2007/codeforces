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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,n,sum,bl,now,last,a[10005];

signed main()
{
	T=read();
	while (T--)
	{
		n=read();sum=0;
		for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
		bl=0;sum+=1;last=0;
		while (sum--)
		{
			now=0;
			for (int i=1;i<=n;i++) 
			  if (a[i]>a[now]&&i!=last) now=i;
			if (now==0) 
			{
				if (bl) cout<<"T"<<endl; else cout<<"HL"<<endl;
				break;
			}
			last=now;
			bl=!bl;
			a[now]--;
		}
	}
}