//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
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
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define int long long 
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}ll n,m,las,pos=1,a[1000002],ans;
bool tp[1000002],vis[1000002];
pair<ll,ll>ad[1000002],mns[1000002];
inline int low(int x){
	return -x&x;
}inline void add(int pos,int v){
	while(pos<=1000000){
		a[pos]+=v;
		pos+=low(pos);
	}
}inline ll qr(int p1,int p2){
	ll rt=0;
	p1--;
	p1=max(0ll,p1);
	while(p1){
		rt-=a[p1];
		p1-=low(p1);
	}while(p2){
		rt+=a[p2];
		p2-=low(p2);
	}return rt;
}
struct t{
	ll a,l,r;
}tt[1000002];
struct s{
	ll b,d,u;
}st[1000002];
inline bool cmp(s a,s b){
	return a.d<b.d;
}inline bool cmp2(t a,t b){
	return a.a<b.a;
}inline bool cmp3(pair<ll,ll> a,pair<ll,ll> b){
	return a.second<b.second;
}
signed main(){
    cin>>n>>m;vis[0]=1;vis[1000000]=1;
    F(i,1,n){
    	cin>>tt[i].a;
    	vis[tt[i].a]=1;
    	cin>>tt[i].l;
    	cin>>tt[i].r;
	}F(i,1,m){
		st[i].b=read();
		st[i].d=read();
		st[i].u=read()+1;
		if(st[i].d==0&&st[i].u==1000001)ans++;
	}
	sort(tt+1,tt+n+1,cmp2);
	sort(st+1,st+m+1,cmp);
	F(i,1,m){
		ad[i]=make_pair(st[i].b,st[i].d);
		mns[i]=make_pair(st[i].b,st[i].u);
	}sort(ad+1,ad+m+1,cmp3);
	sort(mns+1,mns+m+1,cmp3);
	ri p1=1,p2=1,p3=1;
	ad[m+1]=make_pair(-1ll,-1ll);
	mns[m+1]=make_pair(-1ll,-1ll);
	tt[n+1]=(t){-1,-1,-1};
	F(i,0,1000000){
		while(ad[p1].second==i){
			add(ad[p1].first,1);
			p1++;
		}while(mns[p2].second==i){
			add(mns[p2].first,-1);
			p2++;
		}while(tt[p3].a==i){
			if((tt[p3].l==0)&&(tt[p3].r==1000000)){
				ans++;
			}
			ans+=qr(tt[p3].l,tt[p3].r);
			p3++;
		}
	}cout<<ans+1;
    return 0;
}