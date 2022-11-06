#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::sort;
using std::vector;
const int N=1e5+5;
int n,cnt1;
char s[N];
vector<int> V;
signed main()
{
	int last=0;
	register int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='1')
			cnt1++;
	for(i=1;i<=n;i++)
		if(s[i]=='0')
			last++;
		else if(s[i]=='2')
			V.push_back(last),last=0;
	V.push_back(last);
	for(i=0;i<V[0];i++)
		putchar('0');
	for(i=0;i<cnt1;i++)
		putchar('1');
	for(i=1;i<(int)V.size();i++)
	{
		putchar('2');
		for(j=0;j<V[i];j++)
			putchar('0');
	}
	putchar('\n');
	return 0;
}