#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
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

const int N=1.1e5;
int a[N],b[N];
double ss(int a,int b){
	return sqrt((LL)a*a+(LL)b*b);
}
void work(){
	int n=read();
	int m1=0,m2=0;
	F(i,1,2*n){
		int x=read();
		int y=read();
		(x==0?a[m1++]:b[m2++])=x+y;
	}
	assert(m1==n);
	assert(m2==n);
	sort(a,a+n);
	sort(b,b+n);
	double ans=0;
	int s1=0,t1=n-1;
	int s2=0,t2=n-1;
	while(s1<=t1){
		auto p=max(
			max(make_pair(ss(a[s1],b[s2]),0),
			make_pair(ss(a[s1],b[t2]),1)),
			max(make_pair(ss(a[t1],b[s2]),2),
			make_pair(ss(a[t1],b[t2]),3))
		);
		ans+=p.first;
		if(p.second&1)t2--;
		else s2++;
		if(p.second&2)t1--;
		else s1++;
	}
	printf("%.12f\n",ans);
}

int main(){
	int t=read();
	D(_,t)work();
	return 0;
}