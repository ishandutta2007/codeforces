#include<bits/stdc++.h>
using namespace std;
#define ri int
const int maxn=1e5+10;
vector<int>a[maxn];
inline void addedge(int fr,int to){
	a[fr].push_back(to);
	a[to].push_back(fr);
}
int cnt,d,h,n;
signed main(){
	scanf("%d%d%d",&n,&d,&h),++d,++h;
	if(d>=h<<1)return puts("-1"),0;
	if(d==2)return puts(n==2&&h==2?"1 2":"-1"),0;
	cnt=1;
	for(int i=2,pre=1;i<=h;++i,pre=cnt)addedge(pre,++cnt);
	for(int i=h+1,pre=1;i<=d;++i,pre=cnt)addedge(pre,++cnt);
	if(cnt<n){
		for(ri i=1;i<=cnt;++i)
			if(a[i].size()>1){
				for(ri j=cnt+1;j<=n;++j)addedge(i,j);
				goto skip;
			}
		return puts("-1"),0;
		skip:;
	}
	for(ri i=1;i<=n;++i)
		for(ri j:a[i])
			if(i<j)
				printf("%d %d\n",i,j);
	return 0;
}