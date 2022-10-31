#include<cstdio>
#include<algorithm>
using namespace std;
char s[300];
int n;
int main()
{
	scanf("%d%s",&n,s);
	int i;
	int in=0,len=0;
	int anslen=0,cnt=0;
	for(i=0;i<n;i++)
		if(s[i]=='(')
			in++,len=0;
		else if(s[i]==')')
			in--,len=0;
		else if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
			if(!in)
				anslen=max(anslen,++len);
			else if(!len++)
				cnt++;
		}
		else
			len=0;
	printf("%d %d\n",anslen,cnt);
}