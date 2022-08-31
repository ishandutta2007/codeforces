#include<bits/stdc++.h>
#define int64 long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define sqr(x) (x)*(x)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define N 520000
using namespace std;
const double pi=acos(-1);
map<int,int> M;
int L[N],R[N],id[N],a[N],n,m,tree[N],ans[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d%d",&L[i],&R[i]),id[i]=i;
	sort(id+1,id+m+1,[](const int x,const int y){
		return R[x]<R[y];
	});
	int l=0;
	memset(tree,3,sizeof(tree));
	rep(_,1,m){
		int i=id[_];
		while(l<R[i]){
			l++;
			if(!M[a[l]])M[a[l]]=l;
			else{
				int x=M[a[l]];
				for(int j=x;j;j-=j&(-j))tree[j]=min(tree[j],l-x);
				M[a[l]]=l;
			}
		}
		int tmp=1<<30;
		for(int j=L[i];j<=n;j+=j&(-j))tmp=min(tmp,tree[j]);
		ans[i]=tmp;
	}
	rep(i,1,m){
		if(ans[i]>1000000)printf("-1\n");
		else printf("%d\n",ans[i]);
	}
}