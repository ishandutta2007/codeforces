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

int n,m,a[1005][1005],R[1005],C[1005],b1[1000005],b2[1000005],x1,y1,ans[1005][1005];
queue<pair<int,int> >q;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	  {
	  	a[i][j]=read();
	  	R[i]=max(R[i],a[i][j]);
	  	C[j]=max(C[j],a[i][j]);
	  }
	for (int i=1;i<=n;i++) b1[R[i]]=1;
	for (int i=1;i<=m;i++) b2[C[i]]=1;
	for (int i=n*m;i>=1;i--)
	{
		if (b1[i]) x1++;
		if (b2[i]) y1++;
		if (b1[i]||b2[i])
			ans[x1][y1]=i; 
		else
		{
			ans[q.front().first][q.front().second]=i;
			q.pop();
		}
		if (b1[i])
		{
			for (int j=y1-1;j>=1;j--) q.push(make_pair(x1,j));
		}
		if (b2[i])
		{
			for (int j=x1-1;j>=1;j--) q.push(make_pair(j,y1));
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) writesp(ans[i][j]);
		puts("");
	}
}