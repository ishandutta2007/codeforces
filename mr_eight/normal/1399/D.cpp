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
}int t,n,mmin,temp,ans,tp[200002];
bool vis[200002],x;
string ss;
set<int>s0,s1;
void go(int sn,int pos){
	if(sn==0){
		tp[pos]=ans;
		s0.erase(pos);
		temp=*(s1.lower_bound(pos));
		if(temp>INT_MAX/2)return;
		go(1,temp);
	}if(sn){
		tp[pos]=ans;
		s1.erase(pos);
		temp=*(s0.lower_bound(pos));
		if(temp>INT_MAX/2)return;
		go(0,temp);
	}
}
int main(){
    cin>>t;s0.insert(INT_MAX-1);
		s1.insert(INT_MAX-2);
    while(t--){
    	cin>>n;
    	cin>>ss;
    	ans=0;
    	F(i,0,n-1){
    		if(ss[i]=='0')s0.insert(i);
    		else s1.insert(i);
		}
		F(i,0,n){
			tp[i]=0;
		}
    	while((!(s0.size()==1))||(!(s1.size()==1))){
    		ans++;mmin=INT_MAX;x=0;
    		if(!s0.empty()){
    			mmin=*s0.begin();
			}if(!s1.empty()){
				if(*s1.begin()<mmin){
					x=1;
				}
			}if(x){
				go(1,*s1.begin());
			}else{
				go(0,*s0.begin());
			}
		}cout<<ans<<endl;
		F(i,0,n-1){
			cout<<tp[i]<<' ';
		}cout<<endl;
	}
    return 0;
}