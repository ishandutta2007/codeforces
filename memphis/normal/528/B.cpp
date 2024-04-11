#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define ls Tree[t].l
#define rs Tree[t].r
#define mid ((l+r)>>1)
using namespace std;
const int INF=1000000000;
#define N 300005

int i,j,m,n,p,k,f[N],a[N],b[N],tote=1,id[N],ans;

struct Tre{
	int l,r,sum;
}Tree[10000001];

inline bool cmp(int A,int B) { return a[A]<a[B];} 

void ask(int ll,int rr,int &ans,int l,int r,int t){  
	if (!t) return;
   if (ll<=l&&r<=rr) ans=max(ans,Tree[t].sum+1);
   else { 
        if (ll<=mid) ask(ll,rr,ans,l,mid,ls);
         if (rr>mid)  ask(ll,rr,ans,mid+1,r,rs);}
    }

void update(int ll,int c,int l,int r,int t){
	   if (l==r) Tree[t].sum=max(Tree[t].sum,c);
	   else {
	   	     if (ll<=mid)
	   	      {
	   	      	   if (!ls) ls=++tote;
	   	      	   update(ll,c,l,mid,ls);
	   	     }
	   	     else {   
	   	            if (!rs) rs=++tote;
	   	            update(ll,c,mid+1,r,rs);
	   	        }
	   	Tree[t].sum=max(Tree[ls].sum,Tree[rs].sum);
}
}
int main()
{ 
   scanf("%d",&n);
   for (i=1;i<=n;i++){
	  scanf("%d%d",&a[i],&b[i]);
	  id[i]=i;
}
sort(id+1,id+n+1,cmp);
for (i=1;i<=n;i++) 
{ 
   f[i]=1;
   ask(-INF,a[id[i]]-b[id[i]],f[i],-INF,INF,1);
   update(a[id[i]]+b[id[i]],f[i],-INF,INF,1);
   ans=max(ans,f[i]);
}
printf("%d\n",ans);
}