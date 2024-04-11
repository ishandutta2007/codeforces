#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 1010
char s[maxn];
int n;
int last=-1;
int ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	s[n++]='A';
	for (int i=0;i<n;i++)
	if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y')
	{
		ans=max(ans,i-last);
		last=i;
	}
	printf("%d\n",ans);
	return 0;
}