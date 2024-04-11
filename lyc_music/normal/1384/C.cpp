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

int T,n,bl,f[100][100],a[100005],b[100005],ans;
char ch;

signed main()
{
	T=read();
	while (T--)
	{
		n=read();bl=ans=0;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) 
		{
			cin>>ch;
			a[i]=ch-'a'+1;
		}
		for (int i=1;i<=n;i++) 
		{
			cin>>ch;
			b[i]=ch-'a'+1;
			if (b[i]<a[i]) 
			{
				puts("-1");
				bl=1;
				break;
			}
			f[a[i]][b[i]]++;
		}
		if (bl) continue;
		for(int i=1;i<=20;i++)
		  for(int j=i+1;j<=20;j++)
		    if(f[i][j])
			{
		    	for(int k=j+1;k<=20;k++)
		    	  if(f[i][k])f[j][k]+=f[i][k],f[i][k]=0;
		    	ans++;
		    }
		writeln(ans);
	}
}