#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=1000002,Inf=1<<30;
struct p{
	int l,r,k,id;
}a[N];
int n,m,i,ans[N],t;
bool cmp(p u,p v){
	if(u.r!=v.r)
		return u.r<v.r;
	return u.k<v.k;
}
set<pair<int,int> >S;
pair<int,int>x;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
	scanf("%d",&m);
	for(i=n+1;i<=n+m;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].k),a[i].id=i-n;
	sort(a+1,a+n+m+1,cmp);
	S.insert(make_pair(Inf,0));
	for(i=1;i<=n+m;i++)
		if(!a[i].k)
			S.insert(make_pair(a[i].l,a[i].id));
		else
			while(a[i].k--){
				x=*S.lower_bound(make_pair(a[i].l,0));
				if(x!=(make_pair(Inf,0))){
					ans[x.second]=a[i].id;
					S.erase(S.lower_bound(make_pair(a[i].l,0)));
					t++;
				}
				else
					break;
			}
	if(t==n){
		printf("YES\n");
		for(i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	else
		printf("NO\n");
}