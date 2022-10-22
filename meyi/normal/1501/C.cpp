#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int n,p,t;
struct node{
	int id,v;
	inline bool operator<(const node &k)const{
		return v<k.v;
	}
	inline bool operator==(const node &k)const{
		return v==k.v;
	}
}a[maxn];
vector<int>cnt[2500001];
pair<int,int>k[2500001];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		a[i].id=i;
		scanf("%d",&a[i].v);
		cnt[a[i].v].push_back(i);
		if(cnt[a[i].v].size()==4){
			puts("YES");
			for(ri j=0;j<4;++j)printf("%d ",cnt[a[i].v][j]);
			exit(0);
		}
		if(cnt[a[i].v].size()==2){
			if(p){
				puts("YES");
				printf("%d %d %d %d",cnt[p][0],cnt[a[i].v][0],cnt[p][1],cnt[a[i].v][1]);
				exit(0);
			}
			else p=a[i].v;
		}
	}
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i)
		for(ri len=1;i+len<=n;++len){
			ri j=i+len,tmp=a[j].v-a[i].v;
			if(k[tmp].first&&k[tmp].first!=a[i].id&&k[tmp].first!=a[j].id&&k[tmp].second!=a[i].id&&k[tmp].second!=a[j].id){
				puts("YES");
				printf("%d %d %d %d",k[tmp].first,a[j].id,k[tmp].second,a[i].id);
				exit(0);
			}
			else k[tmp]=make_pair(a[i].id,a[j].id);
		}
	puts("NO");
	return 0;
}