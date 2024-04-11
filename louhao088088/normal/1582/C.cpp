#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,m,a,b,c,T,a1,s1,s2,x,ans,len;
char s[maxn];
int get(int x)
{
	int l=1,r=len,sum=0;
	while(l<=r)
	{
		if(s[l]==s[r])l++,r--;
		else if(s[l]==s[x])sum++,l++;
		else if(s[r]==s[x])sum++,r--;
		else return 1e9;
	}
	return sum;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		len=read();ans=1e9;
		scanf("%s",s+1);int l=1,r=len;
		while(l<=r)
		{
			if(s[l]!=s[r])
			{
				ans=min(get(l),get(r));
				if(ans==1e9)puts("-1");
				else cout<<ans<<endl;
				break;
			}
			else l++,r--;
			if(l>=r)
			{
				cout<<0<<endl;break;
			}
		}
	}
 	return 0;
}