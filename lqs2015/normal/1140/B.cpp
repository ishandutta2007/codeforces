#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int t,n,cnt1,cnt2,pos;
char s[555];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		pos=0;cnt1=cnt2=0;
		while(pos<n && s[pos]=='<')
		{
			cnt1++;pos++;
		}
		pos=n-1;
		while(pos>=0 && s[pos]=='>')
		{
			cnt2++;pos--;
		}
		printf("%d\n",min(cnt1,cnt2));
	}
	return Accepted;
}