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
}int n,cnt;
struct s{
	int l,r;
};
vector<s>now,nxt;
vector<int>ans[100002];
inline void merge(){
	for(ri i=0;i<now.size()-1;i++){
		if(now[i].r==now[i+1].l-1){
			now.insert(now.begin()+i,(s)/**/{now[i].l,now[i+1].r});
			now.erase(now.begin()+i+1);
			now.erase(now.begin()+i+1);
			i--;
		}
	}
}inline int sum(int pos){int rt=0;
	while(pos>=0){
		rt+=now[pos].r-now[pos].l+1;pos--;
	}return rt;
}
void solve(){
	F(i,1,now.size()-1){
			F(j,0,i-1){
				if(now[i].r==now[j].l-1){cnt++;
					ans[cnt].push_back((j!=0)+2+(i!=now.size()-1));
					if(j!=0)ans[cnt].push_back(sum(j-1));
					ans[cnt].push_back(now[j].r-now[j].l+1);
					ans[cnt].push_back(sum(i)-sum(j));
					if(i!=now.size()-1){
						ans[cnt].push_back(sum(now.size()-1)-sum(i));
					}
					nxt.clear();
					F(k,i+1,now.size()-1){
						nxt.push_back(now[k]);
					}F(k,j+1,i)nxt.push_back(now[k]);
					nxt.push_back(now[j]);
					F(k,0,j-1)nxt.push_back(now[k]);
					now=nxt;
					merge();
					return;
				}
			}
		}
}
int main(){
    cin>>n;ri temp;
    F(i,1,n){
    	temp=read();
    	now.push_back((s)/**/{temp,temp});
	}
	merge();
	while(now.size()>1){
		solve();
	}cout<<cnt<<endl;
	F(i,1,cnt){
		F(j,0,ans[i].size()-1)cout<<ans[i][j]<<' ';
		putchar('\n');
	}
    return 0;
}