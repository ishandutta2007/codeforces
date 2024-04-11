#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
#define fi first
#define se second
pii a[3];
vector<ppp>ans;
int main(){
	for(ri i=0;i<3;++i)scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a,a+3);
	ans.emplace_back(a[0],pii{a[1].fi,a[0].se});
	ans.emplace_back(pii{a[1].fi,a[0].se},a[1]);
	if(a[2].se>=min(a[0].se,a[1].se)&&a[2].se<=max(a[0].se,a[1].se))ans.emplace_back(pii{a[1].fi,a[2].se},a[2]);
	else if(a[2].se<min(a[0].se,a[1].se)){
		ans.emplace_back(pii{a[1].fi,min(a[0].se,a[1].se)},pii{a[2].fi,min(a[0].se,a[1].se)});
		ans.emplace_back(pii{a[2].fi,min(a[0].se,a[1].se)},a[2]);
	}
	else{
		ans.emplace_back(pii{a[1].fi,max(a[0].se,a[1].se)},pii{a[2].fi,max(a[0].se,a[1].se)});
		ans.emplace_back(pii{a[2].fi,max(a[0].se,a[1].se)},a[2]);
	}
	printf("%d\n",(int)ans.size());
	for(const ppp &i:ans)printf("%d %d %d %d\n",i.fi.fi,i.fi.se,i.se.fi,i.se.se);
	return 0;
}