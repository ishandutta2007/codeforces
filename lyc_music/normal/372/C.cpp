//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 305
#define M 150005
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

int n,m,d,ans,a[M],b[M],t[M],sum,f[3][M];
deque<int>q;

signed main()
{
	n=read(),m=read(),d=read();ans=INT_MAX;
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=m;i++) a[i]=read(),b[i]=read(),t[i]=read(),sum+=b[i];
	for (int i=1;i<=n;i++) f[1][i]=abs(a[1]-i);
	for (int i=2;i<=m;i++)
	{
//		cout<<i<<endl;
		while (!q.empty()) q.pop_front();
		memset(f[i&1],0x3f,sizeof(f[i&1]));
		for (int j=1;j<=n;j++)
		{
			while (!q.empty()&&q.front()<j-(t[i]-t[i-1])*d) q.pop_front();
			while (!q.empty()&&f[i&1^1][q.front()]>f[i&1^1][j]) q.pop_back();
			q.push_back(j);
			f[i&1][j]=min(f[i&1][j],f[i&1^1][q.front()]+abs(a[i]-j));
		}
		while (!q.empty()) q.pop_front();
		for (int j=n;j>=1;j--) 
		{
//			cout<<"!"<<j<<endl;
			while (!q.empty()&&q.front()>j+(t[i]-t[i-1])*d) q.pop_front();
			while (!q.empty()&&f[i&1^1][q.front()]>f[i&1^1][j]) q.pop_back();
			q.push_back(j);	
			f[i&1][j]=min(f[i&1][j],f[i&1^1][q.front()]+abs(a[i]-j));
		}
	}
	for (int i=1;i<=n;i++) ans=min(ans,f[m&1][i]);
	writeln(sum-ans);	  
}