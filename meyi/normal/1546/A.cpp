#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],b,n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri sum=0;
		queue<int>q;
		for(ri i=1;i<=n;++i){
			scanf("%d",&b),a[i]-=b,sum+=a[i];
			if(a[i]<0)q.push(i);
		}
		if(sum){puts("-1");continue;}
		vector<pair<int,int> >ans;
		for(ri i=1;i<=n;++i)
			while(a[i]>0){
				ri p=q.front();q.pop();
				--a[i],++a[p];
				ans.push_back({i,p});
				if(a[p])q.push(p);
			}
		printf("%u\n",ans.size());
		for(auto i:ans)printf("%d %d\n",i.first,i.second);
	}
}