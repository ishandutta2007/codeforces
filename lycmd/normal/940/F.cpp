#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,q,b,cd,cp,tot,a[N],t[N],bb[N],ccnt[N],cnt[N],ans[N];
struct modify{
    int p,bef,aft;
}d[N];
struct query{
    int l,r,t,id;
    int operator<(const query&rhs)const{
        if(l/b!=rhs.l/b)return l/b<rhs.l/b;
        if(r/b!=rhs.r/b)return r/b<rhs.r/b;
        return t<rhs.t;
    }
}p[N];
void add(int x){
	ccnt[cnt[a[x]]]--,ccnt[++cnt[a[x]]]++;
}
void del(int x){
	ccnt[cnt[a[x]]]--,ccnt[--cnt[a[x]]]++;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],t[++tot]=bb[i]=a[i];
    for(int i=1;i<=q;i++){
        int op,x,y,k=cp+1;
        cin>>op>>x>>y;
        if(op==2){
            d[++cd]={x,bb[x],y},t[++tot]=bb[x]=y;
        }else{
            p[++cp]={x,y,cd,k};
        }
    }
    sort(t+1,t+1+tot);
    for(int i=1;i<=n;i++)
    	a[i]=lower_bound(t+1,t+1+tot,a[i])-t;
    for(int i=1;i<=cd;i++)
    	d[i].bef=lower_bound(t+1,t+1+tot,d[i].bef)-t,
    	d[i].aft=lower_bound(t+1,t+1+tot,d[i].aft)-t;
    b=pow(1.0*n*q,1.0/3);
    sort(p+1,p+1+cp);
    int l=1,r=0,t=0;
    for(int i=1;i<=cp;i++){
        while(p[i].l<l)add(--l);
        while(p[i].r>r)add(++r);
        while(p[i].l>l)del(l++);
        while(p[i].r<r)del(r--);
        while(p[i].t<t){
            int p=d[t].p;
            if(l<=p&&p<=r)del(p);
            a[p]=d[t--].bef;
            if(l<=p&&p<=r)add(p);
        }
        while(p[i].t>t){
            int p=d[++t].p;
            if(l<=p&&p<=r)del(p); 
            a[p]=d[t].aft;
            if(l<=p&&p<=r)add(p);
        }
        for(int t=1;;t++)
        	if(!ccnt[t]){
        		ans[p[i].id]=t;break;
			}
    }
    for(int i=1;i<=cp;i++)
        cout<<ans[i]<<"\n";
}