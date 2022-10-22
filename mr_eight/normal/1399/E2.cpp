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
ll t,n,t1,t2,t3,xx,t4,f[200002],rt,ppos,s2s,v[200002],gv2[10000002],num[200002],kans,cnt2,qr[200002],gv[10000002],ans,S,cnt;
vector<int>g[200002],c[200002],co[200002],res[200002];
bool vis[200002];
struct st {
	ll pos,v,num;
	bool operator<(const st&b)const {
		ll temp=((v-v/2)*num),t2=((b.v-b.v/2)*b.num);
		if(temp!=t2)return temp>t2;
		else if(num!=b.num)return num>b.num;
		return pos<b.pos;
	} bool operator>(const st&b)const {
		ll temp=((v-v/2)*num),t2=((b.v-b.v/2)*b.num);
		if(temp!=t2)return temp<t2;
		else if(num!=b.num)return num<b.num;
		return pos>b.pos;
	}
};
multiset<st>s,s2;
void make_tree(int pos) {
	vis[pos]=1;
	ri nxt;
	F(i,0,g[pos].size()-1) {
		nxt=g[pos][i];
		if(!vis[nxt]) {
			f[nxt]=pos;
			v[nxt]=co[pos][i];
			qr[nxt]=res[pos][i];
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
void dfs(int pos) {
	if(c[pos].size()==0) {
		num[pos]=1;
		return;
	}
	F(i,0,c[pos].size()-1) {
		dfs(c[pos][i]);
		num[pos]+=num[c[pos][i]];
	}
}
int main() {
	cin>>t;
	while(t--) {
		s.clear();
s2.clear();
		cin>>n>>S;
		F(i,1,n) {
			g[i].clear();
			c[i].clear();
			co[i].clear();
			res[i].clear();
			vis[i]=0;
			num[i]=0;
		}
		ans=0;
		cnt=0;
		cnt2=0;
		kans=0;
		F(i,2,n) {
			t1=read(),t2=read(),t3=read();
			t4=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
			co[t1].push_back(t3);
			co[t2].push_back(t3);
			res[t1].push_back(t4);
			res[t2].push_back(t4);
		}
		make_tree(1);
		dfs(1);
		F(i,1,n) {
			if(qr[i]==1)s.insert((st) {
				i,v[i],num[i]
			});
			else if(qr[i]==2)s2.insert((st) {
				i,v[i],num[i]
			});
			else if(qr[i]==0){
				s.insert((st) {
					i,v[i],num[i]
				});
				s2.insert((st) {
					i,v[i],num[i]
				});
			}
		}s2s=s2.size();
		F(i,1,n) {
			ans+=v[i]*num[i];
		}
		ans-=S;
		kans=ans;
		while(ans>0) {
			cnt++;
			ri pos=(*s.begin()).pos;
			s.erase(*s.begin());
			ans-=((v[pos]-v[pos]/2)*num[pos]);
			gv[cnt]=((v[pos]-v[pos]/2)*num[pos])+gv[cnt-1];
			v[pos]=v[pos]/2;
			s.insert((st) {
				pos,v[pos],num[pos]
			});
 
			if(gv[cnt]==gv[cnt-1])break;
		}
		ans=kans;
		while(kans>0) {
			cnt2++;
			ri pos=(*s2.begin()).pos;
			s2.erase(*s2.begin());
			kans-=((v[pos]-v[pos]/2)*num[pos]);
			gv2[cnt2]=((v[pos]-v[pos]/2)*num[pos])+gv2[cnt2-1];
			v[pos]=v[pos]/2;
			s2.insert((st) {
				pos,v[pos],num[pos]
			});
 
			if(gv2[cnt2]==gv2[cnt2-1]){ppos=pos;
				break;
			}
		}
		ri j=0;
		xx=1;
		rt=INT_MAX;
		UF(i,cnt2,0) {
			while(gv[j]+gv2[i]<ans) {
				j++;
				if(j>cnt) {
					xx=0;
					break;
				}
			}
			if(xx==0)break;
			rt=min(rt,(ll)(j+i*2));
 
		}
		if(rt==INT_MAX) {
			cout<<n<<' '<<S<<endl;
			F(i,1,n) {
				cout<<f[i]<<' '<<v[i]<<' '<<qr[i]<<' '<<num[i]<<endl;
			}
			for(multiset<st>::iterator d=s2.begin();d!=s2.end();d++){
				cout<<(*d).pos<<' ';
			}cout<<' '<<s2s<<endl;
		} else cout<<rt<<endl;
 
	}
	return 0;
}