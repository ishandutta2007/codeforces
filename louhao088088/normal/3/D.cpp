#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,len,l=0,r=0,b[maxn],k,ans=0,c[maxn];
char a[maxn];
struct node
{
	int num,l;node(int a,int b):num(a),l(b){}
	bool operator <(const node &x)const{return num<x.num;}
};
priority_queue<node>q;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",a+1);len=strlen(a+1);
	for(int i=1;i<=len;i++)
	{
		if(a[i]=='(')l++;
		if(a[i]==')')l--;
		if(a[i]=='?')
		{
			l--;b[i]=read(),c[i]=read();
			q.push(node(c[i]-b[i],i));
		}
		if(l<0)
		{
			if(q.empty())cout<<"-1",exit(0);
			l+=2;node u=q.top();q.pop();ans+=b[u.l];a[u.l]='(';
		}
	}if(len%2==1||l)cout<<"-1",exit(0);
	for(int i=1;i<=len;i++)if(a[i]=='?')ans+=c[i],a[i]=')';
	cout<<ans<<endl;
	for(int i=1;i<=len;i++)
		if(a[i]=='?')putchar(')');
		else printf("%c",a[i]);
	return 0;
}