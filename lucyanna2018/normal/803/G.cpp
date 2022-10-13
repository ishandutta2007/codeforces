#include<stdio.h>
#include<algorithm>
using namespace std;

int n,k;
int val[111111];

int Z;
struct Node{
	int lc, rc;
	int lazy;
	int min_val;
} a[111111 * 50];
int seg[11111];
void build(int&pt,int s,int e){
	pt = ++Z;
	a[pt].lazy = -1;
	if(s == e){
		a[pt].min_val = val[s];
	}else{
		int m = (s+e)/2;
		build(a[pt].lc, s, m);
		build(a[pt].rc, m+1, e);
		a[pt].min_val = min(a[a[pt].lc].min_val, a[a[pt].rc].min_val);
	}
}
void pus(int&pt){
	int w = a[pt].lazy;
	if(w == -1)return;
	int newlc = ++Z;
	a[newlc] = a[a[pt].lc];
	int newrc = ++Z;
	a[newrc] = a[a[pt].rc];
	a[newlc].lazy = w;
	a[newlc].min_val = w;
	a[newrc].lazy = w;
	a[newrc].min_val = w;
	a[pt].lc = newlc;
	a[pt].rc = newrc;
	a[pt].lazy = -1;
}
void upd(int&pt,int s,int e,int l,int r,int x){
	int newpt = ++Z;
	a[newpt] = a[pt];
	if(s == l && e == r){
		a[newpt].lazy = x;
		a[newpt].min_val = x;
		pt = newpt;
		return;
	}
	pus(newpt);
	int m=(s+e)/2;
	if(r<=m)
		upd(a[newpt].lc, s,m,l,r,x);
	else
	if(l>m)
		upd(a[newpt].rc, m+1,e,l,r,x);
	else
	{
		upd(a[newpt].lc, s,m,l,m,x);
		upd(a[newpt].rc, m+1,e,m+1,r,x);
	}
	a[newpt].min_val = min(a[a[newpt].lc].min_val, a[a[newpt].rc].min_val);
	pt = newpt;
}
int qry(int&pt,int s,int e,int l,int r){
	if((s == l && e==r) || a[pt].lazy != -1)
		return a[pt].min_val;
//	pus(pt);
	int m=(s+e)/2;
	if(r<=m)
		return qry(a[pt].lc, s,m,l,r);
	else
	if(l>m)
		return qry(a[pt].rc,m+1,e,l,r);
	else
	return min(qry(a[pt].lc, s,m,l,m),qry(a[pt].rc,m+1,e,m+1,r));
}

struct Node2{
	int lazy, min_val;
} ss[11111 * 4];
void build2(int i,int s,int e){
	ss[i].lazy = -1;
	ss[i].min_val = a[seg[k]].min_val;
	if(s==e)return;
	int m = (s+e)/2;
	build2(i*2,s,m);
	build2(i*2+1,m+1,e);
}
void push(int x){
	int w = ss[x].lazy;
	if(w == -1)return;
	ss[x*2].lazy = ss[x*2].min_val = w;
	ss[x*2+1].lazy = ss[x*2+1].min_val = w;
	ss[x].lazy = -1;
}
void upd_val(int i,int s,int e,int x,int to){
	if(s == e){
		ss[i].lazy = -1;
		ss[i].min_val = to;
		return;
	}
	push(i);
	int m = (s+e)/2;
	if(x <= m)upd_val(i*2, s,m,x,to);else
		upd_val(i*2+1, m+1,e,x,to);
	ss[i].min_val = min(ss[i*2].min_val, ss[i*2+1].min_val);
}
void upd_lazy(int i,int s,int e,int l,int r,int to){
	if(s == l && e==r){
		ss[i].lazy = ss[i].min_val = to;
		return;
	}
	push(i);
	int m = (s+e)/2;
	if(r <= m){
		upd_lazy(i*2, s,m,l,r,to);
	}else
	if(l > m){
		upd_lazy(i*2+1,m+1,e,l,r,to);
	}else{
		upd_lazy(i*2,s,m,l,m,to);
		upd_lazy(i*2+1,m+1,e,m+1,r,to);
	}
	ss[i].min_val = min(ss[i*2].min_val, ss[i*2+1].min_val);
}
int qry_lazy(int i,int s,int e,int x){
	if(s==e || ss[i].lazy!=-1)return ss[i].lazy;
	int m = (s+e)/2;
	if(x <= m)
		return qry_lazy(i*2,s,m,x);
	else
		return qry_lazy(i*2+1,m+1,e,x);
}
int qry_value(int i,int s,int e,int l,int r){
	if(s == l && e == r){
		return ss[i].min_val;
	}
	push(i);
	int m = (s+e)/2;
	if(r <= m)
		return qry_value(i*2,s,m,l,r);
	else
	if(l>m)
		return qry_value(i*2+1,m+1,e,l,r);
	else
		return min(qry_value(i*2,s,m,l,m),qry_value(i*2+1,m+1,e,m+1,r));
}
void vis(int id){
	int w = qry_lazy(1,0,k-1,id);
	if(w != -1){
		upd(seg[id],0,n-1,0,n-1,w);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d",&val[i]);
	build(seg[k],0,n-1);
	for(int i=0; i<k; i++)
		seg[i] = seg[k];
	build2(1,0,k-1);
	int q,t,l,r,x;
	for(scanf("%d",&q); q--;){
		scanf("%d%d%d",&t,&l,&r);
		if(t == 1)scanf("%d",&x);
		--l;--r;
		int idl = l / n, idr = r / n;
		if(idl == idr){
			vis(idl);
			if(t == 1){
				upd(seg[idl], 0, n-1, l - idl * n, r - idl * n, x);
				upd_val(1,0,k-1,idl,a[seg[idl]].min_val);
			}else{
				printf("%d\n",qry(seg[idl], 0, n-1, l - idl * n, r - idl*n));
			}
		}else{
			vis(idl);
			vis(idr);
			if(t == 1){
				upd(seg[idl], 0, n-1, l - idl * n, n-1, x);
				upd_val(1,0,k-1,idl,a[seg[idl]].min_val);
				upd(seg[idr], 0, n-1, 0, r - idr * n, x);
				upd_val(1,0,k-1,idr,a[seg[idr]].min_val);
				if(idl+1 <= idr-1)upd_lazy(1,0,k-1, idl+1, idr-1, x);
			}else{
				vis(idl);
				vis(idr);
				int res = min(
					qry(seg[idl], 0, n-1, l - idl * n, n-1),
					qry(seg[idr], 0, n-1, 0, r - idr * n));
				if(idl+1 <= idr-1)res = min(res, qry_value(1,0,k-1,idl+1,idr-1));
				printf("%d\n",res);
			}
		}
	}
	return 0;
}