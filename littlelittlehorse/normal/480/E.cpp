/*


 
 
log
 
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 2005
using namespace std;
short tu[N][N];//1 0 
//---------------------
int n,m,k,cnt;
const int L=0,R=1; 
struct node{
	int son[2];
	int l,r,mid;
	int st,en,sz,fl,fr;//  38M 
	short le[N],ri[N];
}a[N*2];
int dal[N],dbl[N],ltop,lbot;//1val 2time   (]
int dar[N],dbr[N],rtop,rbot;
int fl,fr;
int test(short *l,short *r,int len){//  -1 
	ltop=lbot=rtop=rbot=0;
	for(int i=1;i<=m;i++){
		if(ltop>lbot&&dbl[lbot+1]<i) lbot++;
		while(ltop>lbot&&l[i]<dal[ltop]) ltop--;
		dal[++ltop]=l[i];dbl[ltop]=i+len-1;
		if(rtop>rbot&&dbr[rbot+1]<i) rbot++;
		while(rtop>rbot&&r[i]<dar[rtop]) rtop--;
		dar[++rtop]=r[i];dbr[rtop]=i+len-1;
		if(i>=len&&dal[lbot+1]+dar[rbot+1]>=len){
			fl=dal[lbot+1];fr=dar[rbot+1];
			return i-len+1;	
		}
	}
	return -1;
}
void update1(int k){// 
	short* ll=a[a[k].son[L]].le,*lr=a[a[k].son[L]].ri,*rr=a[a[k].son[R]].ri,*rl=a[a[k].son[R]].le;
	int erl=0,err=a[k].en-a[k].st+2;//[)
	int st=0,st2=0;
	while(erl+1<err){
		int mid=(erl+err)>>1;
		st=test(lr,rl,mid);
		if(st==-1){
			err=mid;
		}else{
			st2=st,erl=mid;
		}
	}
	a[k].st=st2;a[k].en=st2+erl-1;a[k].fl=fl;a[k].fr=fr;
	for(int i=1,len=a[k].mid-a[k].l+1;i<=m;i++) a[k].le[i]=ll[i]==len? len+rl[i]:ll[i];
	for(int i=1,len=a[k].r-a[k].mid;i<=m;i++) a[k].ri[i]=rr[i]==len? len+lr[i]:rr[i];
	a[k].sz=max(a[a[k].son[L]].sz,a[a[k].son[R]].sz);
	a[k].sz=max(a[k].sz,a[k].en-a[k].st+1);
}
void update2(int k){// 
	short* ll=a[a[k].son[L]].le,*lr=a[a[k].son[L]].ri,*rr=a[a[k].son[R]].ri,*rl=a[a[k].son[R]].le;
	for(int i=1,len=a[k].mid-a[k].l+1;i<=m;i++) a[k].le[i]=ll[i]==len? len+rl[i]:ll[i];
	for(int i=1,len=a[k].r-a[k].mid;i<=m;i++) a[k].ri[i]=rr[i]==len? len+lr[i]:rr[i];
	a[k].sz=max(a[a[k].son[L]].sz,a[a[k].son[R]].sz);
	a[k].sz=max(a[k].sz,a[k].en-a[k].st+1);
}
void update3(int k){// 
	a[k].sz=max(a[a[k].son[L]].sz,a[a[k].son[R]].sz);
	a[k].sz=max(a[k].sz,a[k].en-a[k].st+1);
}
void insert(int k,int x,int y){
	if(a[k].l==a[k].r){
		for(int i=1;i<=m;i++) a[k].le[i]=a[k].ri[i]=tu[x][i];
		for(int i=1;i<=m;i++){
			if(a[k].le[i]==1){
				a[k].st=a[k].en=i;a[k].sz=1;return;
			}
		}
		a[k].st=a[k].en=0;a[k].sz=0;
	}else{
		int mid=(a[k].l+a[k].r)>>1;
		insert(a[k].son[x<=mid? L:R],x,y);
		if(x<=mid+a[k].fr&&x>=mid-a[k].fl+1&&y>=a[k].st&&y<=a[k].en){
			update1(k);
		}else if(a[k].le[y]+a[k].l-1<x&&a[k].r-a[k].ri[y]+1>x){
			update3(k);
		}else update2(k);
	}
}
void build(int &k,int l,int r){
	k=++cnt;a[k].l=l;a[k].r=r;a[k].mid=(l+r)>>1;a[k].en=r-l+1;a[k].st=1;
	if(l==r){
		for(int i=1;i<=m;i++) a[k].le[i]=a[k].ri[i]=tu[l][i];
		for(int i=1;i<=m;i++){
			if(a[k].le[i]==1){
				a[k].st=a[k].en=i;a[k].sz=1;return;
			}
		}
		a[k].st=a[k].en=0;a[k].sz=0;
	}else{
		int mid=(l+r)>>1;
		build(a[k].son[L],l,mid);
		build(a[k].son[R],mid+1,r);
		update1(k);
	}
}
void init(){
	scanf("%d%d%d",&n,&m,&k);
	char s[N];
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			tu[i][j]= s[j]=='.' ? 1:0;	
	}
}
void out(){
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%c",tu[i][j]==1? '.':'x');
}
int root;
int main(){
	init();
	build(root,1,n);// 
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(tu[x][y]==1)	tu[x][y]=0,insert(root,x,y);
		printf("%d\n",a[root].sz);//out();
	}
	return 0;
}