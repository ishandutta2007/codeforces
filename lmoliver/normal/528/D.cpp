#include<bits/stdc++.h>
using namespace std;
#define F(i) for(int i=0;i<n;i++)
const int N=517666+7e3;
const double PI=acos(-1);

struct Comp{
	double r,i;
	Comp(double _r=0,double _i=0){r=_r,i=_i;}
	Comp operator +(const Comp a)const{return Comp(r+a.r,i+a.i);}
	Comp operator -(const Comp a)const{return Comp(r-a.r,i-a.i);}
	Comp operator *(const Comp a)const{return Comp(r*a.r-i*a.i,r*a.i+i*a.r);}
	operator int()const{return round(r);}
};

void dft(int l,Comp *a,Comp *w){
	static int bf[N];
	int n=1<<l;
	bf[0]=0;
	F(i)bf[i]=(bf[i>>1]>>1)|((i&1)<<(l-1));
	F(i)if(i<bf[i])swap(a[i],a[bf[i]]);
	for(int i=2;i<=n;i<<=1){
		int h=i>>1;
		for(int j=0;j<n;j+=i){
			for(int k=0;k<h;k++){
				//a[x]=a0[x2]+xa1[x]
				//a[i]=a[w(i/n)]=a0[w(i/(n/2))]+w(i/n)a1[w(i/(n/2))]
				//a[i+n/2]=a[-i]=a0[]+-a1[]
				Comp x=a[j+k],y=w[n/i*k]*a[j+h+k];
				a[j+k]=x+y;
				a[j+h+k]=x-y;
			}
		}
	}
}
int mul(Comp *a,Comp *b,int al,int bl){
	// for(int i=0;i<al;i++){
	// 	cerr<<a[i].r<<" ";
	// }
	// cerr<<endl;
	// cerr<<"*"<<endl;
	// for(int i=0;i<bl;i++){
	// 	cerr<<b[i].r<<" ";
	// }
	// cerr<<endl;
	static Comp w[N];
	int n=1,l=0;
	while(n<al||n<bl)n<<=1,l++;
	n<<=1,l++;
	F(i)w[i]=Comp(cos(2*PI*i/n),sin(2*PI*i/n));
	dft(l,a,w);
	dft(l,b,w);
	F(i)a[i]=a[i]*b[i];
	F(i)w[i].i*=-1;
	dft(l,a,w);
	F(i)a[i]=a[i]*Comp(1.0/n);
	return n;
}

int getN(int al,int bl){
	int n=1,l=0;
	while(n<al||n<bl)n<<=1,l++;
	n<<=1,l++;
	return n;
}

char sa[N],sb[N];

Comp a[N]={0},b[N]={0};

int res[N]={0};

int la,lb,k;

void findA(char x){
	int xs=0;
	for(int i=0;i<k;i++)
		if(i<la&&sa[i]==x)xs++;
	for(int i=0;i<la;i++){
		if(i+k<la&&sa[i+k]==x)xs++;
		if(i-k-1>=0&&sa[i-k-1]==x)xs--;
		// cerr<<x<<" "<<k<<" "<<i<<":"<<xs<<endl;
		a[i]=xs>0?1:0;
	}
}

void findB(char x){
	for(int i=0;i<lb;i++){
		b[i]=sb[i]==x?1:0;
	}
}

int main(){
	scanf("%*d%*d%d%s%s",&k,sa,sb);
	la=strlen(sa),lb=strlen(sb);
	reverse(sb,sb+lb);

	char s[]="ACGT";

	int n=getN(la,lb);

	for(int i=0;i<4;i++){
		char cc=s[i];
		F(i)a[i]=b[i]=0;
		findA(cc);
		findB(cc);
		mul(a,b,la,lb);
		F(i)res[i]+=a[i];
	}

	int ans=0;
	for(int i=lb;i<=la;i++){
		// cerr<<i<<":"<<res[i-1]<<endl;
		if(res[i-1]==lb){
			// printf("%d ",i-lb+1);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}