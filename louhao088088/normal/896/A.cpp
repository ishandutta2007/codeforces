#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
string c="What are you doing at the end of the world? Are you busy? Will you save us?";
string c2="What are you doing while sending ";
string c3="? Are you busy? Will you send ";
string c4="?";
char ch='"';
int n,m,k,T,F=0,len1,len2,len,s[100005];
void solve(int n)
{
	if(F)return;
	if(n==0)
	{
		if(k<=len)
		{
			cout<<c[k-1];F=1;return;
		}k-=len;return;
	}
	if(k<=len1)
	{
		k--;if(k==len1-1)cout<<ch;
		else cout<<c2[k];F=1;return;
	}
	k-=len1;
	if(F)return;
	if(k<=s[n-1]||n>=55){solve(n-1);return;}
	k-=s[n-1];
	if(F)return;
	if(k<=len2)
	{
		if(k==1||k==len2)cout<<ch;
		else cout<<c3[k-2];F=1;
		return;
	}k-=len2;
	if(F)return;
	if(k<s[n-1]){solve(n-1);return;}
	k-=s[n-1];
	if(F)return;
	if(k<=2)
	{
		if(k==1)cout<<ch;else cout<<"?";F=1;return;
	}k-=2;
	
}
signed main()
{
	len=c.length(),len1=c2.length()+1,len2=c3.length()+2;
	T=read();s[0]=len;
	for(int i=1;i<=55;i++)s[i]=s[i-1]*2+68;
	while(T--)
	{
		n=read(),k=read();F=0;solve(n);
		if(!F)cout<<".";
	}
	return 0;
}