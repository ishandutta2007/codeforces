#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,T,k,ans=0,l[maxn],r[maxn],a[maxn];
signed main()
{
	T=read();
	while(T--)
	{
		for(int i=1;i<=n;i++)l[i]=r[i]=0;
		n=read();//cout<<n<<endl;
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){
			puts("YES");continue;
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]>a[r[i-1]]&&r[i-1]){puts("NO");break;}
			else if(a[i]<a[l[i-1]]&&l[i-1]){puts("NO");break;}
			else if(a[i]>a[i-1])
			{
				if(!r[i-1])r[i-1]=i,l[i]=i-1;
				else if(a[i]<a[r[i-1]])r[i]=r[i-1],l[i]=i-1,r[i-1]=i;
				else if(a[i]==a[r[i-1]])r[i]=r[r[i-1]],l[i]=i-1;
			}
			else if(a[i]<a[i-1])
			{
				if(!l[i-1])l[i-1]=i,r[i]=i-1;
				else if(a[i]>a[l[i-1]])l[i]=l[i-1],r[i]=i-1,l[i-1]=i;
				else if(a[i]==a[l[i-1]])l[i]=l[l[i-1]],r[i]=i-1;
			}
			else if(a[i]==a[i-1])l[i]=l[i-1],r[i]=r[i-1];
			if(i==n)puts("YES");
		}//cout<<"A"<<" "<<n<<endl;
	}
	return 0;
}