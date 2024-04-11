#include<cstdio>
char s[200];
int cnt,n,ans[200];
int main()
{
	scanf("%d%s",&n,s);
	bool flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='W')
			flag=0;
		else{
			if(!flag)
				flag=1,ans[++cnt]=1;
			else
				ans[cnt]++;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d ",ans[i]);
}