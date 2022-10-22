#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,MAXM=2000;
bool nop[MAXN];
int n,q,a[MAXN];
int dv[MAXM];
multiset<ll> st[MAXM];
vector<ll> sum[MAXM];
ll Query(){
	ll res=0;
	for(int i=1; i<=*dv; i++){
		auto it=st[i].end();
		it--;
		res=max(res,*it*(dv[i]));
	}
	return res;
}
int main(){
	n=2e5;
	for(int i=2; i<=n; i++)
		for(int j=i*2; j<=n; j+=i)
			nop[j]=1;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&q);
		*dv=0;
		for(int i=2; i<=n; i++)
			if(!nop[i]&&n%i==0) dv[++*dv]=n/i;
		for(int i=1; i<=*dv; i++){
			sum[i].clear();
			sum[i].resize(dv[i]);
			st[i].clear();
		}
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			for(int j=1; j<=*dv; j++)
				sum[j][i%dv[j]]+=a[i];
		}
		for(int i=1; i<=*dv; i++)
			for(ll j:sum[i])
				st[i].insert(j);
		printf("%lld\n",Query());
		while(q--){
			int p,x;
			scanf("%d%d",&p,&x);
			for(int i=1; i<=*dv; i++){
				st[i].erase(st[i].find(sum[i][p%dv[i]]));
				sum[i][p%dv[i]]=sum[i][p%dv[i]]-a[p]+x;
				st[i].insert(sum[i][p%dv[i]]);
			}
			a[p]=x;
			printf("%lld\n",Query());
		}
	}
	return 0;
}