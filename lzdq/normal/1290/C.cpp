#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int n,k;
char s[MAXN];
int p[MAXN][3];
int pre[MAXN<<1],val[MAXN<<1];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
inline void Merge(int x,int y){
	x=fnd(x),y=fnd(y);
	if(x!=y)
		pre[x]=y,val[y]+=val[x];
}
inline int Calc(int x){
	return min(val[fnd(x)],val[fnd(x+k)]);
}
int ans;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1; i<=k; i++){
		int t,a; scanf("%d",&t);
		while(t--){
			scanf("%d",&a);
			p[a][++*p[a]]=i;
		}
	}
	for(int i=1; i<=k*2; i++)
		pre[i]=i,val[i]=(i>k);
	val[0]=1e9;
	for(int i=1; i<=n; i++){
		if(i>1) printf("%d\n",ans);
		int x=p[i][1],y=p[i][2];
		if(*p[i]==2){
			if(s[i]=='0'){
				if(fnd(x)==fnd(y+k)) continue;
				ans-=Calc(x)+Calc(y);
				Merge(x,y+k),Merge(x+k,y);
				ans+=Calc(x);
			}else{
				if(fnd(x)==fnd(y)) continue;
				ans-=Calc(x)+Calc(y);
				Merge(x,y),Merge(x+k,y+k);
				ans+=Calc(x);
			}
		}else if(*p[i]==1){
			if(x==0) puts("ff");
			if(s[i]=='0'){
				if(fnd(0)==fnd(x)) continue;
				ans-=Calc(x);
				Merge(x,0);
				ans+=Calc(x);
			}else{
				if(fnd(0)==fnd(x+k)) continue;
				ans-=Calc(x);
				Merge(x+k,0);
				ans+=Calc(x);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}