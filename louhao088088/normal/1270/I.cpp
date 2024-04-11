// Problem: CF1270I Xor on Figures
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1270I
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 2022-03-30 21:22:39
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,N,mod,x,y,ans=0;
struct Mat
{
	int a[1005][1005];
	Mat(){memset(a,0,sizeof a);}
	bool operator ~(){for(int i=0;i<n;i++)a[i][i]=1;}
}A,B;
Mat operator *(Mat x,Mat y)
{
	Mat z;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(y.a[i][j])
				for(int k=0;k<n;k++)
					for(int l=0;l<n;l++)
						z.a[(k+i)%n][(l+j)%n]^=(y.a[i][j]*x.a[k][l]);
	return z;
}
void print(Mat a)
{
	for(int i=0;i<n;i++)
		{for(int j=0;j<n;j++)
			cout<<a.a[i][j]<<" ";puts("");}puts("");
}
void Pow(Mat x,int y){while(y){if(y&1)B=B*x;x=x*x;y=y/2;}}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();n=(1<<n);N=n;mod=n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)B.a[i][j]=read();
	m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),A.a[x-1][y-1]=1;
//	print(A);
	
//	print(A*A*A);
	Pow(A,n-1);
//	print(A);//print(B);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)if(B.a[i][j])ans++;
	cout<<ans<<endl;
 	return 0;
}