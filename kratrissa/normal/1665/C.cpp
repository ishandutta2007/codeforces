#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,fa[N],cnt[N],ans;priority_queue<int> q;
bool check(int x){
	int t=0;
	for(int i=0;i<=m;i++){if(cnt[i]>x)t+=cnt[i]-x;x--;}
	return t<=x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),fill(cnt,cnt+n+2,0),ans=0;
		for(int i=2;i<=n;i++)scanf("%d",&fa[i]),cnt[fa[i]]++;cnt[0]++;
		sort(cnt,cnt+n+1,greater<int>());
		for(m=0;cnt[m];m++);m--;
		int l=1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}