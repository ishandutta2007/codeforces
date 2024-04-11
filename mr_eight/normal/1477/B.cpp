//#include <bits/c++config.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define itn int
#define nit int
#define ll unsigned long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define endl '\n'//
#pragma GCC optimize(2)
using namespace std;
int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}
const ll N=200002;
ll sum[N<<2],a[N],p,l[N],r[N];
bool tag1[N<<2],tag0[N<<2];
inline void pushup(ri pos){
	sum[pos]=sum[pos<<1]+sum[pos<<1|1];
}
void build(ll o,ll l,ll r) {
	if(l==r) {
		sum[o]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	pushup(o);
}
inline void pushdown(ri pos,ri l,ri r){
	if(tag0[pos]){
		tag1[pos<<1]=tag1[pos<<1|1]=0;
		tag0[pos<<1]=tag0[pos<<1|1]=1;
		tag0[pos]=0;
		sum[pos<<1]=sum[pos<<1|1]=0;
	}else if(tag1[pos]){
		tag1[pos<<1]=tag1[pos<<1|1]=1;
		tag0[pos<<1]=tag0[pos<<1|1]=0;
		tag1[pos]=0;
		ri mid=r+l>>1;
		sum[pos<<1]=mid-l+1;
		sum[pos<<1|1]=r-mid;
	}
	
	
}
void queryadd(ll pos,ll l,ll r,ll ql,ll qr,bool v) {
	if(ql<=l&&r<=qr) {
		if(v){tag0[pos]=0;
			tag1[pos]=1;
			sum[pos]=r-l+1;
		}else{tag1[pos]=0;
			tag0[pos]=1;
			sum[pos]=0;
		}
		return;
	}//if(ql>r||qr<l)return;
	ll mid=(l+r)>>1;
	pushdown(pos,l,r);
	if(ql<=mid)queryadd(pos<<1,l,mid,ql,qr,v);
	if(qr>mid)queryadd(pos<<1|1,mid+1,r,ql,qr,v);
	pushup(pos);
}
ll querysum(ll o,ll l,ll r,ll ql,ll qr) {
	if(ql<=l&&r<=qr)return sum[o];//if(ql>r||qr<l)return 0;
	pushdown(o,l,r);
	ll ans=0,mid=(l+r)>>1;
	if(ql<=mid)ans=querysum(o<<1,l,mid,ql,qr);
	if(qr>mid)ans+=querysum(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
ll oper,x,y,k,n,m;
string s,f;
int main() {
	p=1e9+7;
	F(qwq,1,read()) {cin>>n>>m;
		F(i,1,4*n)sum[i]=a[i]=tag1[i]=tag0[i]=0;
		cin>>s>>f;
		F(i,1,m){
			l[i]=read(),r[i]=read();
		}
		F(i,1,n)a[i]=f[i-1]-'0';
		build(1,1,n);
		UF(i,m,1) {
			int num=querysum(1,1,n,l[i],r[i]);
			if(r[i]-l[i]+1&1){
				if(num<=(r[i]-l[i]+1>>1)){
					queryadd(1,1,n,l[i],r[i],0);
				}else{
					queryadd(1,1,n,l[i],r[i],1);
				}
			}else{
				if(num==(r[i]-l[i]+1>>1)){
					puts("No");
					goto kkk;
				}if(num<=(r[i]-l[i]+1>>1)){
					queryadd(1,1,n,l[i],r[i],0);
				}else{
					queryadd(1,1,n,l[i],r[i],1);
				}
			}
		}F(i,1,n)if(querysum(1,1,n,i,i)!=s[i-1]-'0'){
			puts("no");
			goto kkk;
		}
		puts("yes");
		kkk:;//F(i,1,n)cerr<<querysum(1,1,n,i,i)<<' ';cerr<<endl;
	}
 
	return 0;
}
/*
1 2
10 6
1111111101
0110001110
1 10
5 9
7 10
1 7
3 5
6 10
*/