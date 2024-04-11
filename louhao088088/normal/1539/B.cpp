#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,sum[maxn],x,y,len;
char ch[maxn];
signed main()
{
	len=read(),m=read();scanf("%s",ch+1);
	for(int i=1;i<=len;i++)sum[i]=sum[i-1]+ch[i]-'a'+1;
	for(int i=1;i<=m;i++)x=read(),y=read(),printf("%lld\n",sum[y]-sum[x-1]); 
	return 0;
}