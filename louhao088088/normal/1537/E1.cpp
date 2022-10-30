#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=5e5+5;
int n,m,nex[maxn],s[maxn],ans1=0,k,id,ans2=0,h;
char a[maxn],b[maxn];
void getnex()
{
	int id=0,p=0,j=0;
	nex[0]=m;
	while(a[j]==a[j+1]&&j+1<m)j++;
	id=1;nex[1]=j;//cout<<j<<endl;//cout<<nex[1]<<endl;//cout<<j<<" "<<m<<endl;
	for(int i=2;i<m;i++)
	{
		int l=nex[i-id];p=id+nex[id];//cout<<l<<" "<<i<<endl;
		if(l+i<p)nex[i]=l;
		else 
		{
			j=max(p-i,0);
			while(a[j+i]==a[j]&&j+i<m)j++;
			id=i;nex[i]=j;//cout<<j<<endl;
		}
	}
}
signed main()
{
	//freopen("P5410_2.in","r",stdin);
	m=read();n=read();
	gets(a);getnex();h=m-1;
	//for(int i=0;i<m;i++)cout<<nex[i]<<" ";cout<<endl;//cout<<n<<" "<<m<<endl;//cout<<s[i]<<" ";
	for(int i=1;i<m;i++)
	{
		if(a[i]>a[0]){h=i-1;break;}
		if(a[i]==a[0])
		{
			//cout<<i<<" "<<nex[i]<<" "<<a[i+nex[i]]<<endl;
			if(a[i+nex[i]]>=a[nex[i]]||i+nex[i]>=m){h=i-1;break;}
			i=i+nex[i];
		}
	}//cout<<n<<" "<<h<<endl;
	for(int j=0,i=0;j<n;i++,j++)
	{
		if(i==h+1)i=0;printf("%c",a[i]);
	}
	return 0;
}