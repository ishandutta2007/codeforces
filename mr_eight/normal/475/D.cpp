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
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
//#pra gma G CC opti mize(3)
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
}
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
int a[100002],n,g[400002],cnt;
map<int,int>qwq[400002],qaq[400002];
map<int,ll>ans;
vector<pair<int,int> >v1,v2;
inline int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
#define mid ((l+r)>>1)
inline int solve(int l,int r){
	if(l==r){
		qwq[++cnt][a[l]]=1;
		qaq[cnt][a[l]]=1;
		g[cnt]=a[l];
		ans[a[l]]++;
		return cnt;
	}ri lc=solve(l,(l+r)>>1),rc=solve((l+r)/2+1,r);
	qwq[++cnt]=qwq[lc];
	qaq[cnt]=qaq[rc];
	ri temp=g[lc];
	F(i,mid+1,r){
		temp=gcd(temp,a[i]);
		qwq[cnt][temp]++;
	}temp=g[rc];
	UF(i,mid,l){
		temp=gcd(temp,a[i]);
		qaq[cnt][temp]++;
	}v1.clear(),v2.clear();
	for(map<int,int>::iterator d=qaq[lc].begin();d!=qaq[lc].end();d++){
		v1.push_back(*d);
	}for(map<int,int>::iterator d=qwq[rc].begin();d!=qwq[rc].end();d++){
		v2.push_back(*d);
	}F(i,0,v1.size()-1){
		F(j,0,v2.size()-1){
			ans[gcd(v1[i].first,v2[j].first)]+=1ll*v1[i].second*v2[j].second;
			//if(gcd(v1[i].first,v2[j].first)==2)cout<<v1[i].first<<' '<<v2[j].first<<'k'<<endl;
		}
	}
	g[cnt]=gcd(g[lc],g[rc]);
	return cnt;
}
int main(){
    cin>>n;
    F(i,1,n){
    	a[i]=read();
	}solve(1,n);
	cin>>n;
	while(n--){
		printf("%lld\n",ans[read()]);
	}
    return 0;
}