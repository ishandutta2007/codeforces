#include<cstdio>
#include<algorithm>
using namespace std;
#define ran 303333
int n,q,lx;
int x[ran * 2],L[ran],R[ran],t[ran];

struct Node{
	int len,_len,sgn;
	void set(int type){
		sgn = type;
		if(sgn == 1)len = 0;else
		if(sgn == 2)len = _len;
	}
} seg[ran * 8];
void push(int i){
	int&tmp = seg[i].sgn;
	if(tmp != -1){
		seg[i*2].set(tmp);
		seg[i*2+1].set(tmp);
		tmp = -1;
	}
}
void merge(int i){
	seg[i].len = seg[i*2].len + seg[i*2+1].len;
}
void build(int i,int s,int e){
	seg[i].len = seg[i]._len = x[e] - x[s];
	seg[i].sgn = -1;
	if(e == s+1)return;
	int m = (s+e)/2;
	build(i*2, s, m);
	build(i*2+1, m, e);
}
void upd(int i,int s,int e,int l,int r,int type){
	if(s == l && e == r){
		seg[i].set(type);
		return;
	}
	push(i);
	int m = (s+e)/2;
	if(r <= m)upd(i*2,s,m,l,r,type);else
		if(l >= m)upd(i*2+1,m,e,l,r,type);else{
			upd(i*2,s,m,l,m,type);
			upd(i*2+1,m,e,m,r,type);
		}
	merge(i);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0; i<q; i++){
		scanf("%d%d%d",&L[i],&R[i],&t[i]);
		++R[i];
		x[lx++] = L[i];
		x[lx++] = R[i];
	}
	x[lx++] = 1;
	x[lx++] = n+1;
	sort(x,x+lx);
	--lx;
	build(1,0,lx);
	for(int i=0; i<q; i++){
		int l = lower_bound(x,x+lx,L[i])-x;
		int r = lower_bound(x,x+lx,R[i])-x;
		upd(1,0,lx,l,r,t[i]);
		printf("%d\n",seg[1].len);
	}
	return 0;
}