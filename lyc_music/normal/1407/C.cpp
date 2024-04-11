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

int n,k1,k2,ans[100005],b[100005],x,y;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	  if(!ans[i])
	  for(int j=1;j<=n;++j)
		if(!ans[j]&&i!=j)
		{
			printf("? %d %d\n? %d %d\n",i,j,j,i);
		    fflush(stdout);
			x=read(),y=read();
			if(x<y)
				ans[j]=y;
			else
			{
				ans[i]=x;
				break;
			}
		}
	printf("! ");
	for (int i=1;i<=n;i++) 
	  if (!ans[i]) writesp(n); else 
	  writesp(ans[i]);fflush(stdout);
	
}