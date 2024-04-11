// Problem: E. Arithmetic Operations
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.ml/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 2022-03-20 21:01:22
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
const int maxn=2e5+105,A=77,N=1e5;
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
map<int,int>f;
int n,a[maxn],ans=0,s[maxn];
void solve1(int x)//A
{
	f.clear();
	for(int i=1;i<=n;i++)f[a[i]-x*i]++;
	for(auto tmp:f)ans=max(ans,tmp.se);
}
void solve2(int x)//A
{
	for(int j=x+1;j<=x+N/A&&j<=n;j++)
		if((a[j]-a[x])%(j-x)==0)
		{
			s[(a[j]-a[x])/(j-x)+N]++;
			ans=max(ans,s[(a[j]-a[x])/(j-x)+N]+1);
		}
	for(int j=x+1;j<=x+N/A&&j<=n;j++)
		if((a[j]-a[x])%(j-x)==0)
			s[(a[j]-a[x])/(j-x)+N]--;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=-A;i<=A;i++)solve1(i);
	for(int i=1;i<=n;i++)solve2(i);
	cout<<n-ans<<endl;
}