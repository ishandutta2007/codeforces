
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn=3e5+7;
 
int root[maxn],tot;
int mm;
int a[maxn],b[maxn];
void quchong(int n){
    sort(b+1,b+1+n);
    mm=unique(b+1,b+1+n)-b-1;
}
 
int getid(int x){
    return lower_bound(b+1,b+1+mm,x)-b;
}
 
struct Tree{
    int lc,rc;
    int sum;
}tree[maxn*50];
 
void pushup(int k){
    tree[k].sum=tree[tree[k].lc].sum+tree[tree[k].rc].sum;
}
 
int build(int l,int r){
    int k=++tot;
    tree[k].sum=0;
    if(l==r) return k;
    int mid=(l+r)>>1;
    tree[k].lc=build(l,mid);
    tree[k].rc=build(mid+1,r);
    return k;
}
 
int updata(int p,int id,int v,int l,int r){
    int k=++tot;
    tree[k]=tree[p];
    if(l==r){
        tree[k].sum+=v;
        return k;
    }
    int mid=(l+r)>>1;
    if(id<=mid) tree[k].lc=updata(tree[p].lc,id,v,l,mid);
    else tree[k].rc=updata(tree[p].rc,id,v,mid+1,r);
    pushup(k);
    return k;
}
int myfind(int p,int id,int l,int r){
    if(l==r) return tree[p].sum;
    int mid=(l+r)>>1;
    if(id<=mid) return tree[tree[p].rc].sum+myfind(tree[p].lc,id,l,mid);
    return myfind(tree[p].rc,id,mid+1,r);
}
int belong[maxn];
int l[maxn],r[maxn];
int n,m;
int ask(int l,int r){
	if(l>r)return 0;
	return myfind(root[r],l,1,n);
}
vector<int>occur[maxn];
int bit[maxn];
void add(int x,int v){
	while(x<=300000){
		bit[x]+=v;
		x+=x&-x;
	}
}
int sum(int x){
	int ret=0;
	while(x){
		ret+=bit[x];
		x-=x&-x; 
	}
	return ret;
}
int main(){
    scanf("%d%d",&m,&n);
    memset(r,-1,sizeof r);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
		if(occur[a[i]].empty()){
			r[a[i]]=a[i]+sum(3e5)-sum(a[i]);
			add(a[i],1);
		}
        occur[a[i]].push_back(i);
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++)occur[i].push_back(n+1);
    quchong(n);
    root[0]=build(1,n);
    for(int i=1;i<=n;++i){
        int id=getid(a[i]);
        if(belong[id]){
            int t=updata(root[i-1],belong[id],-1,1,n);
            root[i]=updata(t,i,1,1,n);
        }else{
            root[i]=updata(root[i-1],i,1,1,n);
        }
        belong[id]=i;
    }
    for(int i=1;i<=m;i++){
    	l[i]=i;if(occur[i][0]==n+1)r[i]=i+sum(3e5)-sum(i);
    	if(occur[i].size()>1)l[i]=1;
    	for(int j=1;j<occur[i].size();j++){
    		r[i]=max(r[i],1+ask(occur[i][j-1]+1,occur[i][j]-1));
		}
		printf("%d %d\n",l[i],r[i]);
	}
    return 0;
}