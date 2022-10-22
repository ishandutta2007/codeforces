#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=3e5+5;
int n,m,a[MAXN],cnt[MAXN],ac[MAXN];
ll ans;
vector<int> b[MAXN];
set<pr> ed;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),cnt[i]=0;
		sort(a+1,a+n+1);
		for(int i=1,j=1; i<=n; i++){
			if(i>1&&a[i]!=a[i-1]) j=i;
			cnt[j]++;
		}
		ed.clear();
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			x=lower_bound(a+1,a+n+1,x)-a;
			y=lower_bound(a+1,a+n+1,y)-a;
			ed.insert(mkp(x,y));
			ed.insert(mkp(y,x));
		}
		ans=0;
		m=0;
		for(int i=1; i<=n; i++)
			if(cnt[i]) ac[++m]=cnt[i];
		sort(ac+1,ac+m+1);
		m=unique(ac+1,ac+m+1)-ac-1;
		for(int i=1; i<=m; i++)
			b[i].clear();
		for(int i=1; i<=n; i++)
			if(cnt[i]) b[lower_bound(ac+1,ac+m+1,cnt[i])-ac].push_back(i);
		for(int i=1; i<=m; i++)
			sort(b[i].begin(),b[i].end()),reverse(b[i].begin(),b[i].end());
		for(int i=1; i<=m; i++){
			for(int j=0; j<b[i].size(); j++){
				int k=j+1;
				while(k<b[i].size()&&ed.find(mkp(b[i][j],b[i][k]))!=ed.end()) k++;
				if(k<b[i].size()) ans=max(ans,2ll*ac[i]*(a[b[i][j]]+a[b[i][k]]));
			}
			for(int j=1; j<=m; j++){
				if(i==j) continue;
				for(int k=0; k<b[j].size(); k++){
					if(ed.find(mkp(b[j][k],b[i].front()))==ed.end()){
						ans=max(ans,1ll*(ac[i]+ac[j])*(a[b[j][k]]+a[b[i].front()]));
						break;
					}
					int l=1;
					while(l<b[i].size()&&ed.find(mkp(b[j][k],b[i][l]))!=ed.end()) l++;
					if(l<b[i].size()) ans=max(ans,1ll*(ac[i]+ac[j])*(a[b[j][k]]+a[b[i][l]]));
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}