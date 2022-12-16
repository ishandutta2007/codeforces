#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n,m;

int g;
LL r,rr;
int nn,mm;
int n1,m1;
int calc_arg(int n,int m){
	if(n==1)return 0;
	D(i,n)if((LL)i*m%n==1)return i;
	abort();
}
LL mg(int x,int y){
	if(x%g!=y%g)return -1;
	LL ans=((LL)x/g*mm%rr*n1%rr+(LL)y/g*nn%rr*m1%rr)%rr;
	return ans*g+x%g;
}

const int A=1.1e6;
int a1[A],a2[A];

int main(){
	n=read();
	m=read();
	g=gcd(n,m);
	r=(LL)n*m/g;
	nn=n/g;
	mm=m/g;
	// cerr<<nn<<" "<<mm<<endl;
	rr=(LL)nn*mm;
	n1=calc_arg(nn,mm);
	m1=calc_arg(mm,nn);
	LL k=read();
	D(i,n)a1[read()]=i+1;
	D(i,m)a2[read()]=i+1;
	
	vector<LL> good;
	D(i,A)if(a1[i]&&a2[i]){
		int x=a1[i]-1;
		int y=a2[i]-1;
		LL res=mg(x,y);
		if(res!=-1)good.push_back(res);
	}
	sort(good.begin(),good.end());
	LL bads=r-good.size();
	LL loops=(k-1)/bads;
	LL rest=k-bads*loops;
	// D(i,good.size()){
	// 	cerr<<"good["<<i<<"]="<<good[i]<<endl;
	// }
	good.push_back(1e18);
	LL last=loops*r;
	D(i,good.size()){
		LL sz=i?good[i]-good[i-1]-1:good[i];
		if(sz>=rest){
			last+=rest;
			printf("%lld\n",last);
			exit(0);
		}
		else{
			rest-=sz;
			last+=sz+1;
		}
	}
	cerr<<"not found"<<endl;
	abort();
}