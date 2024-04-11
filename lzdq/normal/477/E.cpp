#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=4e5+5,INF=0x3fffffff;
typedef pair<int,int> pr;
#define mkp make_pair
int n,q,a[MAXN],op[MAXN][3];
vector<int> v1[MAXN],v2[MAXN];
int ans[MAXN];
int top,stk[MAXN],sa[MAXN];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
pr sum[MAXN<<2];
pr operator +(pr a,pr b){
	return mkp(min(a.first,b.first),min(a.second,b.second));
}
inline void pushup(int k){
	sum[k]=sum[lc]+sum[rc];
}
void Modify(int k,int l,int r,int x,int y){
	if(l==r){
		sum[k]=mkp(y+sa[x],y-sa[x]);
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y);
	else Modify(rs,x,y);
	pushup(k);
	return ;
}
pr Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return sum[k];
	int mid=l+r>>1;
	pr res(INF,INF);
	if(x<=mid) res=res+Query(ls,x,y);
	if(mid<y) res=res+Query(rs,x,y);
	return res;
}
int Query(int l,int r,int y){
	int w=lower_bound(sa+l,sa+r,y)-sa,res=INF;
	if(l<w) res=min(res,Query(1,1,n,l,w-1).second+y);
	if(w<r) res=min(res,Query(1,1,n,w,r-1).first-y);
	return res;
}
void Calc(vector<int> *vec){
	top=0;
	for(int i=1; i<=n; i++){
		while(top&&sa[top]>=a[i]) top--;
		stk[++top]=i;
		sa[top]=a[i];
		Modify(1,1,n,top,-2*i);
		for(int j:vec[i]){
			int x1=op[j][0],&y1=op[j][1],x2=i,y2=op[j][2];
			ans[j]=1+x2-x1+y2;
			int w=lower_bound(stk+1,stk+top+1,x1)-stk,w1,w2;
			if(y1>sa[w]) y1=sa[w],w1=w;
			else w1=lower_bound(sa+1,sa+w+1,y1)-sa;
			ans[j]=min(ans[j],x2-x1+abs(y2-y1));
			ans[j]=min(ans[j],Query(1,w1,y2)+x1+x2);
			ans[j]=min(ans[j],1+Query(w1,w,y2)+x1+x2);
			w2=lower_bound(sa+w,sa+top+1,y2)-sa;
			ans[j]=min(ans[j],1+x2-x1+sa[w2]-y2);
			if(w2>w) ans[j]=min(ans[j],1+x2-x1+y2-sa[w2-1]);
		}
	}
	top=0;
	for(int i=n; i; i--){
		while(top&&sa[top]>=a[i]) top--;
		stk[++top]=i;
		sa[top]=a[i];
		Modify(1,1,n,top,2*i);
		for(int j:vec[i]){
			int x1=op[j][0],y1=op[j][1],x2=i,y2=op[j][2];
			int w=lower_bound(sa+1,sa+top+1,y1)-sa;
			ans[j]=min(ans[j],1+Query(w,top,y2)-x1-x2);
			ans[j]=min(ans[j],Query(1,w,y2)-x1-x2);
		}
	}
	return ;
}
int main(){
	//freopen("paimon.in","r",stdin);
	//freopen("paimon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	scanf("%d",&q);
	for(int i=1; i<=q; i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2) x1=n+1-x1,x2=n+1-x2,v2[x2].push_back(i);
		else v1[x2].push_back(i);
		op[i][0]=x1;
		op[i][1]=y1;
		op[i][2]=y2;
	}
	Calc(v1);
	reverse(a+1,a+n+1);
	Calc(v2);
	for(int i=1; i<=q; i++)
		printf("%d\n",ans[i]);
	return 0;
}
//fuckccf