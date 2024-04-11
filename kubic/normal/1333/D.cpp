#include <bits/stdc++.h>
using namespace std;
#define N 3005
#define M 3000005
int n,m,ps,t,cnt,nw;char a[N];vector<int> z[M],ans[M];
int main()
{
	scanf("%d %d %s",&n,&m,a+1);ps=m;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<n;++j) if(a[j]=='R' && a[j+1]=='L') z[i].push_back(j);
		for(int j=0;j<z[i].size();++j) a[z[i][j]]='L',a[z[i][j]+1]='R';
		if(!z[i].size()) {ps=i-1;break;}cnt+=z[i].size();
	}for(int i=1;i<n;++i) if(a[i]=='R' && a[i+1]=='L') {puts("-1");return 0;}
	if(cnt<m) {puts("-1");return 0;}t=m-ps;
	for(int i=1;i<=ps;++i)
	{
		ans[++nw].push_back(z[i][0]);
		for(int j=1;j<z[i].size();++j)
			if(t) --t,ans[++nw].push_back(z[i][j]);
			else ans[nw].push_back(z[i][j]);
	}
	for(int i=1;i<=nw;++i) if(ans[i].size())
	{
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();++j) printf("%d ",ans[i][j]);puts("");
	}return 0;
}