#include<cstdio>
#include<algorithm>
#include<vector>
using std::min;
using std::sort;
using std::reverse;
using std::vector;
const int N=1e6+5;
int n,k,sum;
char s[N];
vector<int> V;
inline void solve()
{
	int lst=-1,cnt=0,cc;
	register int i;
	V.clear();
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='W')
			cnt++;
	if(cnt==0&&k==0)
		return printf("0\n"),void();
	cc=cnt+k;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='L'&&s[i-1]=='W')
			lst=i;
		if(s[i]=='L'&&s[i+1]=='W')
		{
			if(~lst)
				V.push_back(i-lst+1);
		}
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	while(!V.empty())
		if(k>=V.back())
			k-=V.back(),V.pop_back();
		else
			break;
	printf("%d\n",2*min(n,cc)-((int)V.size()+1));
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}