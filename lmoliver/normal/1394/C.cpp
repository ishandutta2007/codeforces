#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

int ax,ay;
bool ok(int xl,int xr,int yl,int yr,int dl,int dr){
	// cerr<<"ok ["<<xl<<","<<xr<<"] ["<<yl<<","<<yr<<"] ["<<dl<<","<<dr<<"]"<<endl;
	if(xl>xr||yl>yr||dl>dr)return false;
	int rdl=xl-yr;
	int rdr=xr-yl;
	// cerr<<rdl<<" "<<rdr<<endl;
	if(rdr>=dl&&dr>=rdl){
		int d=xr-yr;
		if(d>=dl&&d<=dr){
			ax=xr;
			ay=yr;
		}
		else if(d<=dr){
			ax=xr;
			ay=yr-(dl-d);
		}
		else{
			ax=xr-(d-dr);
			ay=yr;
		}
		// cerr<<"a=("<<ax<<","<<ay<<")"<<endl;
		return ax||ay;
	}
	return false;
}

void dmax(int &a,int b){a=max(a,b);}
void dmin(int &a,int b){a=min(a,b);}

const int N=500500;
int n;
int x[N],y[N];
bool test(int d){
	// cerr<<"test d="<<d<<endl;
	int xl=0,xr=1e8,yl=0,yr=1e8,dl=-1e8,dr=1e8;
	F(i,1,n){
		dmax(xl,x[i]-d);
		dmin(xr,x[i]+d);
		dmax(yl,y[i]-d);
		dmin(yr,y[i]+d);
		dmax(dl,x[i]-y[i]-d);
		dmin(dr,x[i]-y[i]+d);
	}
	return ok(xl,xr,yl,yr,dl,dr);
}
int main(){
	n=read();
	static char s[N];
	F(i,1,n){
		scanf("%s",s);
		int l=strlen(s);
		D(j,l)(s[j]=='N'?x[i]:y[i])++;
	}
	// F(i,1,n)cerr<<"["<<i<<"]=("<<x[i]<<","<<y[i]<<")"<<endl;
	int l=0,r=1e7;
	while(l<r){
		int mid=(l+r)>>1;
		if(test(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	test(l);
	// cerr<<"a=("<<ax<<","<<ay<<")"<<endl;
	D(_,ax)putchar('N');
	D(_,ay)putchar('B');
	printf("\n");
	return 0;
}