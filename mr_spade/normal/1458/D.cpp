#include<cstdio>
#include<cstring>
#include<set>
using std::set;
const int N=1e6+5;
int n;
char s[N];
int l[N],r[N];
set<int> S;
int cur;
inline void left()
{
	l[cur]--;
	if(l[cur]==0)
		S.erase(cur);
	cur--;putchar('0');
	return;
}
inline void right()
{
	r[cur]--;
	cur++;putchar('1');
	return;
}
inline void walk()
{
	if(l[cur])
	{
		if(cur>0&&r[cur-1])
			return left();
		else if(*S.rbegin()==cur)
			return left();
	}
	return right();
}
inline void solve()
{
	register int i;
	scanf("%s",s+1);n=strlen(s+1);
	memset(l,0,sizeof(int)*(n<<1|1));
	memset(r,0,sizeof(int)*(n<<1|1));
	cur=n;
	for(i=1;i<=n;i++)
		if(s[i]=='0')
			l[cur]++,cur--;
		else
			r[cur]++,cur++;
	for(i=0;i<=n<<1;i++)
		if(l[i])
			S.insert(i);
	cur=n;
	for(i=1;i<=n;i++)
		walk();
	putchar('\n');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}