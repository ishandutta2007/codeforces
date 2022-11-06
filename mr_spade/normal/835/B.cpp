#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
const int N(1e6+5);
char n[N];
int k,len,sum,ans;
signed main()
{
	int i,j;
	scanf("%d",&k);
	scanf("%s",n+1);
	len=strlen(n+1);
	for(i=1;i<=len;i++)
		sum+=n[i]-'0';
	if(sum>=k)
	{
		puts("0");
		return 0;
	}
	sort(n+1,n+len+1);
	for(i=1;i<=len;i++)
	{
		sum+='9'-n[i];
		ans++;
		if(sum>=k)
			break;
	}
	printf("%d\n",ans);
	return 0;
}