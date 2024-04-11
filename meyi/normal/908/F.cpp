#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int g,lst[3],mx[3],n,pos[maxn],to[256],val[maxn];
char op[5];
ll ans;
signed main(){
	to['G']=0,to['R']=1,to['B']=2;
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%s",pos+i,op);
		val[i]=to[*op];
		if(!g&&!val[i])g=i;
	}
	if(!g){
		ri l=0,ll=0,r=0,rr=0;
		for(ri i=1;i<=n;++i)
			if(val[i]==1)r=pos[i];
			else rr=pos[i];
		for(ri i=n;i;--i)
			if(val[i]==1)l=pos[i];
			else ll=pos[i];
		ans=r-l+rr-ll;
	}
	else{
		lst[0]=lst[1]=lst[2]=pos[g];
		for(ri i=g-1;i;--i){
			ans+=min(lst[0],lst[val[i]])-pos[i];
			lst[val[i]]=pos[i];
		}
		lst[0]=pos[g],lst[1]=lst[2]=0;;
		for(ri i=g+1;i<=n;++i){
			if(val[i]){
				ans+=pos[i]-max(lst[0],lst[val[i]]);
				ckmax(mx[val[i]],pos[i]-max(lst[0],lst[val[i]]));
			}
			else{
				for(int j:{1,2}){
					ans+=pos[i]-lst[j];
					ckmax(mx[j],pos[i]-lst[j]);
				}
				if(mx[1]+mx[2]>pos[i]-lst[0])ans+=pos[i]-lst[0],ans-=mx[1]+mx[2];
				mx[1]=mx[2]=0;
			}
			lst[val[i]]=pos[i];
		}
	}
	printf("%lld",ans);
	return 0;
}