#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
int const N=233333,INF=0x3f3f3f3f;
int n,q,B,cur,cd,cp,tim,m,t[N],a[N],bb[N],cnt[N],ccnt[N],ans[N];
struct linked_list{
	int H,T=N-1,l[N],r[N];
	void insert(int x){
		r[l[T]]=x,l[x]=l[T],r[x]=T,l[T]=x;
	}
	void erase(int x){
		l[r[x]]=l[x],r[l[x]]=r[x];
	}
	void get(int&m,int*t){
		m=0;
		for(int i=H;i^T;i=r[i])
			if(i)t[m++]=i;
	}
};
linked_list s;
struct modify{
	int p,bef,aft;
}d[N];
struct query{
	int l,r,k,t,id;
	int operator<(const query&rhs)const{
		if(l/B!=rhs.l/B)
			return l/B<rhs.l/B;
		if(r/B!=rhs.r/B)
			return r/B<rhs.r/B;
		return t<rhs.t;
	}
}p[N];
void add(int x){
	if(!--ccnt[cnt[a[x]]])
		s.erase(cnt[a[x]]);
	if(!ccnt[++cnt[a[x]]]++)
		s.insert(cnt[a[x]]);
}
void del(int x){
	if(!--ccnt[cnt[a[x]]])
		s.erase(cnt[a[x]]);
	if(!ccnt[--cnt[a[x]]]++)
		s.insert(cnt[a[x]]);
}
int ask(int k){
	s.get(m,t);
	sort(t,t+m);
	int res=INF;
	for(int i=0,j=0,w=0;i<m;w-=ccnt[t[i++]]){
		while(j<m&&w<k)
			w+=ccnt[t[j++]];
		if(j==m&&w<k)
			break;
		res=min(res,t[j-1]-t[i]);
	}
	return res<INF?res:-1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	B=cbrtl(n)*cbrtl(n)+1;
	for(int i=1;i<=n;i++)
		cin>>a[i],bb[i]=a[i];
	for(int i=1;i<=q;i++){
		int op,x,y,k,t=cp+1;
		cin>>op>>x>>y;
		if(op>1)
			d[++cd]={x,bb[x],y},bb[x]=y;
        else
			cin>>k,p[++cp]={x,y,k,cd,t};
	}
	sort(p+1,p+1+cp);
	int l=1,r=0,t=0;
	for(int i=1;i<=cp;i++){
		while(p[i].l<l)
			add(--l);
		while(p[i].r>r)
			add(++r);
		while(p[i].l>l)
			del(l++);
		while(p[i].r<r)
			del(r--);
		while(p[i].t<t){
			int p=d[t].p;
			if(l<=p&&p<=r)
				del(p);
			a[p]=d[t--].bef;
			if(l<=p&&p<=r)
				add(p);
		}
		while(p[i].t>t){
			int p=d[++t].p;
			if(l<=p&&p<=r)
				del(p); 
			a[p]=d[t].aft;
			if(l<=p&&p<=r)
				add(p);
		}
		ans[p[i].id]=ask(p[i].k);
	}
	for(int i=1;i<=cp;i++)
		cout<<ans[i]<<"\n";
}