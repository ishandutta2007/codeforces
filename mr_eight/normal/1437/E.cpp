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
int n,k,a[500002],dp[500002],q[500002],v[500002],l,r,temp,qwqaqwq,ans=INT_MAX;
bool ban[500002];
map<int,int>mp;
map<int,int>::iterator d,nxt;
inline void push(int pos){
	/*while(l<=r&&dp[pos]-pos<=dp[q[r]]-q[r])r--;
	q[++r]=pos,v[++r]=a[pos];*/
	mp[a[pos]]=min(mp[a[pos]],dp[pos]-pos);
	d=mp.find(a[pos]);d++;
	while(d!=mp.end()&&(d->second)>dp[pos]-pos){
		nxt=d;d++;mp.erase(nxt);
	}
}inline int getmp(int v){
	if(mp.empty())return 1e9;
	d=mp.upper_bound(v);
	if(d==mp.begin())return 1e9;
	d--;
	return d->second;
}
int main(){
    cin>>n>>k;
    F(i,1,n)a[i]=read()-i;
    F(i,1,k)ban[qwqaqwq=read()]=1;
    memset(dp,0x3f,sizeof(dp));
    mp[-INT_MAX]=0;
    F(i,1,n){
    	if(mp.empty()){
    		if(ban[i]){
    			cout<<-1;
    			return 0;
			}
    		continue;
		}//temp=q[upper_bound(v+l,v+r+1,a[i])-1-v];
    	dp[i]=i+getmp(a[i])-1;
    	if(dp[i]>1e6){
    		if(ban[i]){
    			cout<<-1;
    			return 0;
			}else continue;
		}
    	if(!ban[i])push(i);
    	else{
    		mp.clear();
    		mp[a[i]]=dp[i]-i;
		}
	}F(i,qwqaqwq,n){
		ans=min(ans,dp[i]+n-i);
	}cout<<((ans<1e6)?ans:-1);
//	F(i,1,n)cout<<endl<<dp[i];
    return 0;
}