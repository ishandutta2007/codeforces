#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define N 300010
#define L a[t<<1]
#define R a[t<<1|1]
#define mid ((l+r)>>1)
#define lfs t<<1,l,mid
#define rfs t<<1|1,mid+1,r
struct data{int lu,ld,ru,rd,la,ra,aa;ll k;}a[N<<2];
void mer(int t,int l,int r){
	int ls=mid-l+1,rs=r-mid;
	a[t]=(data){
		L.lu==ls?ls+R.lu:L.lu,
		L.ld==ls?ls+R.ld:L.ld,
		R.ru==rs?rs+L.ru:R.ru,
		R.rd==rs?rs+L.rd:R.rd,
		0,0,0
	};
	a[t].la=L.lu==ls?ls+R.la:(L.la==ls?ls+R.ld:L.la);
	a[t].ra=R.rd==rs?rs+L.ra:(R.ra==rs?rs+L.ru:R.ra);
	a[t].aa=max(L.ra+R.ld,max(L.ru+R.la,
		max(L.aa,max(R.aa,max(a[t].la,a[t].ra)))));
}
void up(int t){
	if (a[t].k<0) a[t]=(data){0,1,0,1,1,1,1,a[t].k}; else
	if (a[t].k>0) a[t]=(data){1,0,1,0,1,1,1,a[t].k}; else
		a[t]=(data){0,0,0,0,0,0,0,0};
}
void add(int t,int l,int r,int x,int k){
	if (l==r) a[t].k+=k,up(t); else
	x<=mid?add(lfs,x,k):add(rfs,x,k),mer(t,l,r);
}
ll n,m,i,x,y,k,b[N];
inline int rd(){int t;scanf("%d",&t);return t;}
int main(){
	n=rd();
	for (i=1;i<=n;i++) b[i]=rd(),
		i-1?(add(1,2,n,i,b[i]-b[i-1]),0):0;
    m=rd();
	while (m--){
		x=rd(),y=rd(),k=rd();
		if (x-1) add(1,2,n,x,k);
		if (y-n) add(1,2,n,y+1,-k);
		cout<<a[1].aa+1<<"\n";
	}
	return 0;  
}