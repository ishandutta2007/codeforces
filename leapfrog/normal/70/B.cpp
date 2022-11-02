#include<bits/stdc++.h>
using namespace std;
int n,len,ans=0,sum,cnt=0,gg[1000005];
char a[1000005];
int main()
{
	scanf("%d",&n),cin.getline(a+1,1000004),cin.getline(a+1,1000004),len=strlen(a+1)+1;
	int l=1;for(int i=1;i<=len;i++)
	{
		while(i<=len&&a[i]!='.'&&a[i]!='!'&&a[i]!='?') i++;
		if(l!=len) gg[++cnt]=i-l+1,l=i+1;
		while(l<=len&&a[l]==' ') l++;
	}
	for(int i=1;i<=cnt;i++) if(gg[i]>n) return puts("Impossible"),0;
	sum=gg[1];
	for(int i=2;i<=cnt;i++) if(sum+gg[i]+1<=n) sum+=gg[i]+1;else sum=gg[i],ans++;
	ans+=!!sum;
	return printf("%d\n",ans),0;
}