//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 5010
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

int n,m,a[N],s[N],sum[N],f[N][N];
struct node
{
	int x,s;
}b[N];

bool Cmp(node x,node y)
{
	return x.x<y.x;
}

deque<int>q;

signed main()
{
	n=read(),m=read();memset(f,0x3f,sizeof(f));f[0][0]=0;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) b[i].x=read(),b[i].s=read();
	sort(b+1,b+m+1,Cmp);
	for (int i=1;i<=m;i++) s[i]=s[i-1]+b[i].s;
	if (s[m]<n) return puts("-1"),0;
	for (int i=1;i<=m;i++)
	{
		f[i][0]=0;
		while (!q.empty()) q.pop_front();
		q.push_back(0);
		for (int j=1;j<=s[i]&&j<=n;j++)
		{
			f[i][j]=f[i-1][j];sum[j]=sum[j-1]+abs(a[j]-b[i].x);
			while((j-q.front()>b[i].s)&&(!q.empty())||(!q.empty())&&f[i-1][q.front()]-sum[q.front()]>f[i-1][j]-sum[j]) q.pop_front();
            q.push_back(j),f[i][j]=min(f[i][j],sum[j]+f[i-1][q.front()]-sum[q.front()]);
//            cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<q.front()<<endl;
        }
    }
	writeln(f[m][n]);
}