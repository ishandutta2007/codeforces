#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int n,flag[maxn],a[maxn],st[maxn],x;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();flag[0]=n+1;int l=n+1;
	for(int i=n;i>=1;i--)
	{
		if(flag[i])continue;int num=0;st[++num]=i;
		for(int j=n;j>=1;j--)
		{
			if(num==n)
			{
				num++;break;
			}cout<<"? ";
			for(int k=1;k<=n;k++)
				if(k!=i)cout<<1<<" ";
				else cout<<1+num<<" ";cout<<endl;
			cout.flush();
			x=read();st[++num]=x;if(flag[x]||x==i)break;
		}num--;int u=1;
		while(num)
		{
			flag[st[num]]=l-u;u++;
			//cout<<st[num]<<" "<<num<<endl;
			num--;
		}l=flag[i];
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<flag[i]<<" ";cout<<endl;cout.flush();
 	return 0;
}