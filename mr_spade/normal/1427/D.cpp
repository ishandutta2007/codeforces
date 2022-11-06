#include<cstdio>
#include<algorithm>
#include<vector>
using std::reverse;
using std::vector;
const int N=1e5+5;
int n;
int p[N],ip[N];
vector<int> V;
inline bool solve()
{
	int k,pos;
	register int i;
	for(i=1;i<=n;i++)
		ip[p[i]]=i;
	for(i=1;i<=n-1;i++)
		if(ip[i+1]<ip[i])
			goto end;
	return 0;
	end:;k=i;
	for(i=ip[k+1]+1;p[i]==p[i-1]+1;i++);
	pos=i-1;
	V.push_back(4-(ip[k+1]==1)-(ip[k]==n));
	reverse(p+1,p+ip[k+1]);
	V.push_back(ip[k+1]-1);
	reverse(p+ip[k+1],p+pos+1);
	V.push_back(pos-ip[k+1]+1);
	reverse(p+pos+1,p+ip[k]+1);
	V.push_back(ip[k]-pos);
	reverse(p+ip[k]+1,p+n+1);
	V.push_back(n-ip[k]);
	reverse(p+1,p+n+1);
	V.push_back(-1);
	return 1;
}
signed main()
{
	int cnt=0;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	while(solve())
		cnt++;
	printf("%d\n",cnt);
	for(int x:V)
		if(x==-1)
			putchar('\n');
		else if(x)
			printf("%d ",x);
	return 0;
}