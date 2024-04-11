#include<bits/stdc++.h>
using namespace std;

#define F(i) for(int i=0;i<n;i++)
const int N=400400;
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

int n;
Comp a[N]={0},b[N]={0};
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x;
		scanf("%d",&x);
		a[i].r=x;
	}
	for(int i=0;i<n-1;i++){
		b[i].r=1;
	}
	mul(a,b,n-1,n-1);
	printf("%d",(int)((long long)n*(n+1)/2-round(a[n-2].r)));
}