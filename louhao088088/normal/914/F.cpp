
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int len,num,opt,l,r,x,n,ans1,ans2,len1;
bitset<100005>a[27],b;
char s[100005],c;
int main()
{
	scanf("%s",s);len1=strlen(s);
	for(int i=0;i<len1;i++)
	{
		a[s[i]-'a'][i+1]=1;//cout<<int(s[i]-'a')<<endl;cout<<a[s[i]-'a']<<endl;
	}
	n=read();
	for(int i=1;i<=n;i++)
	{
		opt=read();
		if(opt==1)
		{
			scanf("%d %c",&x,&c);a[s[x-1]-'a'][x]=0;
			a[c-'a'][x]=1;s[x-1]=c;
		}
		else
		{
			l=read(),r=read();char s2[100005]={0};scanf("%s",s2);
			len=strlen(s2);b.set();//cout<<b<<endl;
			for(int j=0;j<len;j++)
			{
				b=b&(a[s2[j]-'a']>>j);//cout<<b<<endl;cout<<int(s2[j]-'a')<<endl;cout<<(a[s2[j]-'a']>>j)<<endl;
			}
			ans1=(b>>l).count(),ans2=(b>>(r-len+2)).count();
			if(ans1-ans2<0)ans1=ans2;
			printf("%d\n",ans1-ans2);
		}
	}
	
	return 0;
}