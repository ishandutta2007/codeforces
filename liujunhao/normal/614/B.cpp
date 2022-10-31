#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans;
bool f;
char s[100050],a[100050];
int main()
{
	scanf("%d",&n);
	int i,j,cnt1;
	a[0]='1';
	for(i=1;i<=n;i++){
		scanf("%s",s);
		cnt1=0;
		if(s[0]=='0'){
			puts("0");
			return 0;
		}
		for(j=0;s[j];j++){
			if(s[j]!='1'&&s[j]!='0')
				break;
			if(s[j]=='1')
				cnt1++;
			if(cnt1>1)
				break;
		}
		if(s[j])
			memcpy(a,s,sizeof s);
		else
			ans+=j-1;
	}
	printf("%s",a);
	for(i=1;i<=ans;i++)
		printf("0");
}