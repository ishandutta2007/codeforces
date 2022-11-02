#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int N=400002;
const long long Inf=1ll<<60;
typedef long long ll;
struct qj{
	ll L,R,id;
	bool operator<(const qj &k)const{
		return k.R>R;
	}
}x[N];
ll n,m,i,j,k,l[N],r[N],ans[N];
struct P{
	ll val,id;
	bool operator<(const P &k)const{
		return k.val>val;
	}
}a[N],Y;
multiset<P>S;
void init(){
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",l+i,r+i);
	for(i=1;i<=m;i++)
		scanf("%lld",&a[i].val),a[i].id=i;
}
bool cmp(P u,P v){
	return u.val<v.val;
}
void work(){
	for(i=1;i<n;i++)
		x[i]=(qj){l[i+1]-r[i],r[i+1]-l[i],i};
	sort(x+1,x+n);
	sort(a+1,a+m+1,cmp);
	S.insert((P){1ll<<60,0});
	for(i=j=1;i<n;i++){
		while(j<=m&&a[j].val<=x[i].R){
			S.insert(a[j]);
			j++;
		}
		Y=*S.lower_bound((P){x[i].L,0});
		if(Y.val==Inf){
			printf("No");
			return;
		}
		//printf("%lld %lld\n",x[i].id,Y.id);
		ans[x[i].id]=Y.id;
		S.erase(S.lower_bound((P){x[i].L,0}));
	}
	printf("Yes\n");
	for(i=1;i<n;i++)
		printf("%lld ",ans[i]);
}
int main(){
	init();
	work();
}