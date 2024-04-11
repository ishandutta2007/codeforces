#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	int x=0,p=1;char c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//purplesun
const int N=1e5+10;
vector<int>v1[N],v2[N];
int p[N],n,sz,a[N];
//
struct T{
	int dat[N<<2],tag[N<<2],dat2[N<<2];
	void init(int ok){
		memset(tag,0,sizeof(tag));
		rep(i,2*sz-1){
			dat[i]=ok*INF;
			dat2[i]=ok*INF;
		}
	}
	void pd(int k){
		if(k*2+2<(N<<2)&&tag[k]!=0){
			tag[2*k+1]+=tag[k];
			tag[2*k+2]+=tag[k];
			dat[2*k+1]+=tag[k];
			dat[2*k+2]+=tag[k];
			dat2[2*k+1]+=tag[k];
			dat2[2*k+2]+=tag[k];
			tag[k]=0;
		}
	}
	void modify(int x,int y,int l,int r,int k){
		pd(k);
		if(l>=y||x>=r)return;
		if(x<=l&&r<=y){
			dat[k]--;
			dat2[k]--;
			tag[k]--;
			return;
		}
		int mid=(l+r)>>1;
		modify(x,y,l,mid,2*k+1);
		modify(x,y,mid,r,2*k+2);
		dat[k]=min(dat[2*k+1],dat[2*k+2]);
		dat2[k]=max(dat2[2*k+1],dat2[2*k+2]);
	}
	void modify2(int x,int l,int r,int k,int v){
		pd(k);
		if(r-l==1){
			dat[k]=v;
			dat2[k]=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<mid)modify2(x,l,mid,2*k+1,v);
		else modify2(x,mid,r,2*k+2,v);
		dat[k]=min(dat[2*k+1],dat[2*k+2]);
		dat2[k]=max(dat2[2*k+1],dat2[2*k+2]);
	}
	int query(bool ok){
		pd(0);
		if(ok)return dat2[0];
		else return dat[0];
	}
};
T T1,T2;
int main(){
	n=getint();
	rep(i,n){
		int x=getint()-1;
		p[x]=i;
	}
	sz=1;
	while(sz<n)sz<<=1;
	T1.init(-1);
	T2.init(1);
	rep(i,n){
		a[i]=getint()-1;
		if(i>=p[a[i]]){
			T2.modify2(a[i],0,sz,0,i-p[a[i]]);
		}
		else{
			T1.modify2(a[i],0,sz,0,i-p[a[i]]);
		}
	}
	rep(i,n){
		v1[i+1].push_back(a[i]);
		v2[((i-p[a[i]])%n+n)%n+1].push_back(a[i]);
	}
	rep(i,n){
		int ans0,ans1;
		if(i){
			T1.modify(0,n,0,sz,0);
			T2.modify(0,n,0,sz,0);
			rep(j,v2[i].size()){
				int x=v2[i][j];
				T2.modify2(x,0,sz,0,INF);
				T1.modify2(x,0,sz,0,-1);
			}
			rep(j,v1[i].size()){
				int x=v1[i][j];
				T1.modify2(x,0,sz,0,-INF);
				T2.modify2(x,0,sz,0,n-1-p[x]);
			}
			//cout<<"-------------------"<<endl;
			
		}
		ans0=abs(T1.query(true));
		ans1=T2.query(false);
		printf("%d\n",min(ans0,ans1));
	}
	return 0;
}