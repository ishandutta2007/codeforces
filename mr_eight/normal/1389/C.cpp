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
ll t,cnt,ans;
string s;
bool c;
int main() {
	cin>>t;
	while(t--) {
		cin>>s;
		ans=0;
		F(i,'0','9') {
			F(j,'0','9') {if(i!=j){
				
			
				c=0;
				F(k,0,s.size()-1) {
					if(c==0) {
						if(s[k]==i) {
							c=1;
						}
					} else {
						if(s[k]==j) {
							c=0;
							cnt++;
						}
					}
				}
				ans=max(cnt*2,ans);
				cnt=0;
			}else{
				cnt=0;
				F(k,0,s.size()-1){
					if(s[k]==i)cnt++;
				}ans=max(ans,cnt);
				cnt=0;
			}}
 
		}
		cout<<s.size()-ans<<endl;
	}
	return 0;
}