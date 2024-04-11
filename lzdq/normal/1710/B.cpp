#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,den[MAXN],pos[MAXN],pl[MAXN],pr[MAXN];
int ax[MAXN];
struct node{
	ll a,b,c;
}mx[19][MAXN];
node operator +(node a,node b){
	return node{max(a.a,b.a),max(a.b,b.b),max(a.c,b.c)};
}
int lg[MAXN];
ll s1[MAXN],s2[MAXN];
node Query(int l,int r){
	int k=lg[r-l+1];
	return mx[k][l]+mx[k][r-(1<<k)+1];
}
char ans[MAXN];
int main(){
	n=2e5;
	lg[0]=-1;
	for(int i=1; i<=n; i++)
		lg[i]=lg[i>>1]+1;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d%d",pos+i,den+i),ax[i]=pos[i];
		sort(ax+1,ax+n+1);
		*ax=unique(ax+1,ax+n+1)-ax-1;
		for(int i=1; i<=*ax; i++)
			s1[i]=s2[i]=0;
		for(int i=1; i<=n; i++){
			int p=pos[i],d=den[i];
			pl[i]=lower_bound(ax+1,ax+*ax+1,p-d)-ax;
			pr[i]=upper_bound(ax+1,ax+*ax+1,p+d)-ax-1;
			pos[i]=lower_bound(ax+1,ax+*ax+1,p)-ax;
			s1[pl[i]]++;
			s1[pos[i]+1]-=2;
			s1[pr[i]+1]++;
			s2[pl[i]]-=p-d;
			s2[pos[i]+1]+=p-d;
			s2[pos[i]+1]+=p+d;
			s2[pr[i]+1]-=p+d;
		}
		for(int i=1; i<=*ax; i++){
			s1[i]+=s1[i-1],s2[i]+=s2[i-1];
			mx[0][i].a=s1[i]*ax[i]+s2[i];
			mx[0][i].b=mx[0][i].a+ax[i];
			mx[0][i].c=mx[0][i].a-ax[i];
			//printf("x %d a %lld b %lld c %lld s1 %lld s2 %lld\n",ax[i],mx[0][i].a,mx[0][i].b,mx[0][i].c,s1[i],s2[i]);
		}
		for(int j=1; j<=lg[*ax]; j++)
			for(int i=1; i+(1<<j)-1<=*ax; i++)
				mx[j][i]=mx[j-1][i]+mx[j-1][i+(1<<j-1)];
		for(int i=1; i<=n; i++){
			int p=ax[pos[i]],d=den[i];
			ll res=0;
			if(pl[i]>1) res=max(res,Query(1,pl[i]-1).a);
			res=max(res,Query(pl[i],pos[i]).c+(p-d));
			if(pos[i]<pr[i]) res=max(res,Query(pos[i]+1,pr[i]).b-(p+d));
			if(pr[i]<*ax) res=max(res,Query(pr[i]+1,*ax).a);
			//printf("i %d res %lld\n",i,res);
			ans[i]='0'+(res<=m);
		}
		ans[n+1]=0;
		puts(ans+1);
	}
	return 0;
}