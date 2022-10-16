/*
Author: QAQAutomaton
Lang: C++
Code: D.cpp 
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
int n,k;
pii ask(int x){
	putchar('?');
	for(int i=1;i<=k+1;++i)if(i!=x)printf(" %d",i);
	putchar('\n');
	fflush(stdout);
	int a,b;
	cin>>a>>b;
	return make_pair(b,a);
}
signed main(){
	cin>>n>>k;
	pii a=ask(k+1);
	pii b=ask(a.y);
	if(a>b)swap(a,b);
	int ans=1;
	for(int i=1;i<=k+1;++i)if(i!=b.y && i!=a.y){
		ans+=ask(i).y==b.y;
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}