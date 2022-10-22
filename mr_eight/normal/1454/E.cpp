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
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
template<class T>
inline T read(T &x) {
	x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	if(fu)x=-x;
}
inline int read(){
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
ll t,n,size[200002],f[200002],t1,t2;
bool vis[200002],mark[200002];
vector<int>g[200002];
ll ans;
bool fin;
inline void dfs(int pos,int fa){vis[pos]=1;f[pos]=fa;
	F(i,0,g[pos].size()-1){if(fin)return;
		if(vis[g[pos][i]]){
			if(g[pos][i]==fa)continue;
			else{ri temp=pos;
				mark[g[pos][i]]=1;
				while(pos!=g[temp][i]){
					mark[pos]=1;
					pos=f[pos];
				}pos=temp;fin=1;continue;
			}
		}else dfs(g[pos][i],pos);
	}
}
inline void go(int pos){
	ll t1=0,t2=0,t3=0;
	vis[pos]=1;size[pos]=1;
	F(i,0,g[pos].size()-1){
		if(vis[g[pos][i]])continue;
		go(g[pos][i]);
		size[pos]+=size[g[pos][i]];
		t1+=size[g[pos][i]];
		t2+=size[g[pos][i]]*size[g[pos][i]];
	}ans+=(t1*t1-t2)/2+t1;//cout<<pos<<' '<<ans<<endl;
}
int main(){
    cin>>t;
    while(t--){fin=0;
    	cin>>n;
    	F(i,1,n){
    		size[i]=f[i]=0;
    		vis[i]=mark[i]=0;
    		g[i].clear();
		}F(i,1,n){
			read(t1),read(t2);
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}dfs(1,0);
		F(i,1,n){//cout<<mark[i]<<' ';
			vis[i]=mark[i];
		}ll q1=0,q2=0;ans=0;
		F(i,1,n){
			if(mark[i]){
				go(i);
				q1+=size[i];
				q2+=size[i]*size[i];
			}
		}ans+=q1*q1-q2;
		cout<<ans<<'\n';
	}
    return 0;
}