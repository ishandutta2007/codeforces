//#include <bits/c++config.h>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
using namespace __gnu_pbds;
inline int read() {
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
ll t,n,t1,t2,t3,f[200002],v[200002],num[200002],ans,S,cnt;
vector<int>g[200002],c[200002],co[200002];
bool vis[200002];
struct st{
	ll pos,v,num;
	bool operator<(const st&b)const{
		ll temp=((v-v/2)*num),t2=((b.v-b.v/2)*b.num);
		if(temp!=t2)return temp>t2;
		else if(num!=b.num)return num>b.num;
		return pos<b.pos;
	}bool operator>(const st&b)const{
		ll temp=((v-v/2)*num),t2=((b.v-b.v/2)*b.num);
		if(temp!=t2)return temp<t2;
		else if(num!=b.num)return num<b.num;
		return pos>b.pos;
	}
};
set<st>s;
void make_tree(int pos){
	vis[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			v[nxt]=co[pos][i];
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}void dfs(int pos){
	if(c[pos].size()==0){
		num[pos]=1;
		return;
	}F(i,0,c[pos].size()-1){
		dfs(c[pos][i]);
		num[pos]+=num[c[pos][i]];
	}
}
int main(){
	cin>>t;
	while(t--){
		s.clear();
	
    cin>>n>>S;
    F(i,1,n){
    	g[i].clear();
    	c[i].clear();
    	co[i].clear();
    	vis[i]=0;
    	num[i]=0;
	}ans=0;cnt=0;
    F(i,2,n){
    	t1=read(),t2=read(),t3=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
    	co[t1].push_back(t3);
    	co[t2].push_back(t3);
	}make_tree(1);
	dfs(1);
	F(i,2,n){
		s.insert((st){i,v[i],num[i]});
	}F(i,1,n){
		ans+=v[i]*num[i];
	}ans-=S;
	while(ans>0){
		cnt++;
		ri pos=(*s.begin()).pos;
		s.erase(s.begin());
		ans-=((v[pos]-v[pos]/2)*num[pos]);
		v[pos]=v[pos]/2;
		s.insert((st){pos,v[pos],num[pos]});
	}cout<<cnt<<endl;}
    return 0;
}