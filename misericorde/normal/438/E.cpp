#include <bits/stdc++.h>
#define ll long long
#define p 998244353
#define g 3
#define maxn 800005
int a[maxn]={0},b[maxn]={0},cl[maxn],d[maxn]={0},d2[maxn]={0},res[maxn]={0},s[maxn]={0},rev[maxn],n,m;
int qpow(int a,int b){
	if (b==0) return 1;
	int d=qpow(a,b>>1);d=(ll)d*d%p;
	if (b&1)d=(ll)d*a%p;
	return d;
}

void NTT(int *a,int type,int lim){
	for (int i=0;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
    for (int i=0;i<lim;++i)
        if(i<rev[i])std::swap(a[i],a[rev[i]]);
    for (int len=1;len<lim;len<<=1){
        int wn=qpow(g,(p-1)/(len<<1)),r=len<<1;
        if (type==-1) wn=qpow(wn,p-2);
        for (int j=0;j<lim;j+=r)
	    for (int w=1,k=0;k<len;++k,w=(ll)w*wn%p){
	        int x=a[j+k];
	        int y=(ll)w*a[j+k+len]%p;
	        a[j+k]=(x+y)%p;
	        a[j+k+len]=(x-y+p)%p;        
	    }
    }if (type==-1) 
		for (int i=0;i<lim;++i)a[i]=(ll)a[i]*qpow(lim,p-2)%p;
}

void polyInv(int len,int *a,int *c){
	if (len==1){c[0]=qpow(a[0],p-2);return;}
	polyInv((len+1)>>1,a,c);
	int lim=1;while (lim<(len<<1))lim<<=1;
	for (int i=0;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	for (int i=len;i<lim;++i)c[i]=0;
	for (int i=0;i<len;++i)cl[i]=a[i];
	for (int i=len;i<lim;++i)cl[i]=0;
	NTT(cl,1,lim);NTT(c,1,lim);
	for (int i=0;i<lim;++i)c[i]=(ll)(2ll-(ll)cl[i]*c[i]%p+p)%p*(ll)c[i]%p;
	NTT(c,-1,lim);for (int i=len;i<lim;++i)c[i]=0;
}

/*
C*C = A mod x^(n/2)
B*B = A mod x^n
B^2-C^2 = 0 mod x^(n/2)
(B+C)(B-C) = 0 mod x^(n/2)
B-C=0 mod x^(n/2)
B^2-2BC+C^2 = 0 mod x^n
A-2BC+C^2=0 mod x^n
A+C^2=2BC mod x^n
B=(A+C^2)/2C = (A/C+C)/2
*/
/*
void polySqrt(int len,int *a,int *b){
    if(len==1) return (void)(b[0]=a[0]);
    polySqrt(len>>1,a,b);
    for(int i=0;i<len;++i) cl[i]=a[i];
    polyInv(len,b,d);
    NTT(cl,1,len<<1),NTT(d,1,len<<1);
    for(int i=0,l=len<<1;i<l;++i) d[i]=(ll)d[i]*cl[i]%p;
    NTT(d,-1,len<<1);
    for(int i=0;i<len;++i) b[i]=(ll)(b[i]+d[i])%p*qpow(2,p-2)%p;
    for(int i=0,l=(len<<1);i<l;++i) cl[i]=d[i]=0;
}*/

void polySqrt(int len,int *a,int *c){
	if (len==1){c[0]=a[0];return;}
	polySqrt((len+1)>>1,a,c);
	polyInv(len,c,d);
	int lim=1;
	while (lim<=(len<<1)) lim<<=1;
	for (int i=len;i<lim;++i)cl[i]=c[i]=d[i]=0;
	for (int i=0;i<len;++i)cl[i]=a[i];
	for (int i=0;i<lim;++i)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	NTT(d,1,lim);NTT(cl,1,lim);
	for (int i=0;i<lim;++i)cl[i]=(ll)cl[i]*d[i]%p;
	NTT(cl,-1,lim);
	for (int i=0;i<len;++i)cl[i]=(ll)(cl[i]+c[i])%p*qpow(2,p-2)%p;
	for (int i=0;i<len;++i)c[i]=cl[i];
}
	

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		int t;
		scanf("%d",&t);s[t]++;
	}for (int i=1;i<=m;++i)s[i]=(p-4*s[i])%p;
	s[0]++;
	int lim=1;while (lim<=m)lim<<=1;
	polySqrt(lim,s,d2);
	d2[0]=(d2[0]+1)%p;
	polyInv(lim,d2,res);
	for (int i=0;i<=m;++i)res[i]=res[i]*2%p;
	for (int i=1;i<=m;++i)printf("%d\n",res[i]);
}