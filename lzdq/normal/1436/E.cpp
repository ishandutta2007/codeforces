#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5,MAXM=2e7+5;
int n,a[MAXN];
vector<int> vec[MAXN];
#define ls lc[k],l,mid
#define rs rc[k],mid+1,r
int cntp,rt[MAXN],lc[MAXM],rc[MAXM],mx[MAXM];
inline void pushup(int k){
	mx[k]=min(mx[lc[k]],mx[rc[k]]);
}
void Build(int &k,int l,int r,int x,int y){
	k=++cntp;
	if(l==r){
		if(l==x) mx[k]=y;
		//else mx[k]=1e9;
		return ;
	}
	int mid=l+r>>1;
	Build(ls,x,y);
	Build(rs,x,y);
	pushup(k);
	return ;
}
void Modify(int p,int &k,int l,int r,int x,int y){
	k=++cntp;
	if(l==r){
		mx[k]=y;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) rc[k]=rc[p],Modify(lc[p],ls,x,y);
	else lc[k]=lc[p],Modify(rc[p],rs,x,y);
	pushup(k);
	return ;
}
int Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return mx[k];
	int res=1e9,mid=l+r>>1;
	if(x<=mid) res=min(res,Query(ls,x,y));
	if(mid<y) res=min(res,Query(rs,x,y));
	return res;
}
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		if(i==1) Build(rt[i],1,n,a[i],i);
		else Modify(rt[i-1],rt[i],1,n,a[i],i);
		vec[a[i]].push_back(i);
		if(a[i]>1) ans=2;
	}
	if(!ans){
		puts("1");
		return 0;
	}
	rt[n+1]=rt[n];
	for(int i=2; i<=n+1; i++){
		int x=0;
		vec[i].push_back(n+1);
		for(int j=0;j<vec[i].size();j++){
			int y=vec[i][j];
			if(Query(rt[y],1,n,1,i-1)>x){
				ans=i+1;
				//printf("find %d x %d y %d\n",i,x,y);
				break;
			}
			x=y;
		}
		if(ans<=i) break;
	}
	printf("%d\n",ans);
	return 0;
}