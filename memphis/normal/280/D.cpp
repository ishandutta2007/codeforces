#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 100005
typedef pair<int,int> pii;
const int inf=(int)1e4;

struct flag{
	int lm,rm,mx,sum,lmr,rml;
	pii lmxr;
	flag(int lm=0,int rm=0,int mx=0,int sum=0,int lmr=0,int rml=0,pii lmxr=pii(0,0))
	:lm(lm),rm(rm),mx(mx),sum(sum),lmr(lmr),rml(rml),lmxr(lmxr){}
};

inline flag plu(const flag &a,const flag &b){
	return flag(
		max(a.lm,a.sum+b.lm),
		max(b.rm,b.sum+a.rm),
		max(a.mx,max(b.mx,a.rm+b.lm)),
		a.sum+b.sum,
		a.lm>a.sum+b.lm?a.lmr:b.lmr,
		b.rm>b.sum+a.rm?b.rml:a.rml,
		a.mx>=b.mx&&a.mx>=a.rm+b.lm?a.lmxr:(b.mx>=a.mx&&b.mx>=a.rm+b.lm?b.lmxr:pii(a.rml,b.lmr))
	);
}

struct seg{
	seg *l,*r;
	int rev,cle;
	flag a,b,c,d;

	void updata1(){a=plu(l->a,r->a);}
	
	void updata2(){b=plu(l->b,r->b);}
	
	void updata3(){
		c=plu(l->c,r->c);
		d=plu(l->d,r->d);
	}
	
	void rever(){
		rev^=1;
		swap(c,d);
	}
	
	void clear(){
		cle=1;
		c=a;
		d=b;
		rev=0;
	}
	
	void downdata(){
		if(cle){
			if(l) l->clear();
			if(r) r->clear();
			cle=0;
		}
		if(rev){
			if(l) l->rever();
			if(r) r->rever();
			rev=0;
		}
	}		
	
}t[N<<2];
int tn;

int n,L,R,a[N],m;

flag query(seg *x,int l,int r,int a,int b){
	if(l==a && b==r) return x->c;
	int mid=l+r>>1;
	x->downdata();
	flag ans;
	if(b<=mid) ans=query(x->l,l,mid,a,b);
	else if(a>mid) ans=query(x->r,mid+1,r,a,b);
	else ans=plu(query(x->l,l,mid,a,mid),query(x->r,mid+1,r,mid+1,b));
	x->updata3();
	return ans;
}

void modify(seg *x,int l,int r,int a,int b){
	if(l==a && b==r) {x->rever();return;}
	int mid=l+r>>1;
	x->downdata();
	if(b<=mid) modify(x->l,l,mid,a,b);
	else if(a>mid) modify(x->r,mid+1,r,a,b);
	else modify(x->l,l,mid,a,mid),modify(x->r,mid+1,r,mid+1,b);
	x->updata3();
}

void modify2(seg *x,int l,int r,int k){
	if(l==r) {
		x->a=flag(a[k],a[k],a[k],a[k],k,k,pii(k,k));
		x->b=flag(-a[k],-a[k],-a[k],-a[k],k,k,pii(k,k));
		x->c=x->a;
		x->d=x->b;
		return;
	}
	int mid=l+r>>1;
	x->downdata();
	if(k<=mid) modify2(x->l,l,mid,k);
	else modify2(x->r,mid+1,r,k);
	x->updata1();
	x->updata2();
	x->updata3();
}

void work1(){
	for(tn=1;tn<n;tn<<=1);
	rep(i,1,n){
		t[i+tn-1].a=flag(a[i],a[i],a[i],a[i],i,i,pii(i,i));
		t[i+tn-1].b=flag(-a[i],-a[i],-a[i],-a[i],i,i,pii(i,i));
		t[i+tn-1].c=t[i+tn-1].a;
		t[i+tn-1].d=t[i+tn-1].b;
	}
	rep(i,tn+n,tn<<1){
		t[i].a=t[i].b=t[i].c=t[i].d=
		flag(-inf,-inf,-inf,-inf,i-tn+1,i-tn+1,pii(i-tn+1,i-tn+1));
	}
	dep(i,tn-1,1){
		t[i].l=t+(i<<1);
		t[i].r=t+(i<<1|1);
		t[i].updata1();
		t[i].updata2();
		t[i].updata3();
	}
	scanf("%d",&m);
	int u,x,y,z;
	while(m--){
		scanf("%d",&u);
		if(u==0){
			scanf("%d%d",&x,&y);
			a[x]=y;
			modify2(t+1,1,tn,x);
		}
		else{
			scanf("%d%d%d",&x,&y,&z);
			int tot=0;
			while(z--){
				flag ans=query(t+1,1,tn,x,y);
				if(ans.mx>0){
					tot+=ans.mx;
					modify(t+1,1,tn,ans.lmxr.first,ans.lmxr.second);
				}
				else break;
			}
			printf("%d\n",tot);
			t[1].clear();
		}
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	work1();
}