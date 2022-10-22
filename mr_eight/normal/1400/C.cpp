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
}
int t,n,x;
string s;
bool vis[100002],num[100002],op;
inline bool ok(int pos){
	if(s[pos]=='1'){
	if(pos>x){
		if(vis[pos-x]){
			if(num[pos-x])return 1;
		}else{
			num[pos-x]=1;
			vis[pos-x]=1;
			return 1;
		}
	}if(pos+x<=n){
		if(vis[pos+x]){
			if(num[pos+x])return 1;
		}else{
			num[pos+x]=1;
			vis[pos+x]=1;
			return 1;
		}
	}return 0;
	
	}else{
		if(pos>x&&pos+x<=n){
			if(vis[pos-x]&&vis[pos+x]){
				if(num[pos-x]==0&&num[pos+x]==0)return 1;
				else return 0;
			}if(vis[pos-x]){
				if(num[pos-x]==0){
					vis[pos+x]=1;
					num[pos+x]=0;
					return 1;
				}else return 0;
			}if(vis[pos+x]){
				if(num[pos+x]==0){
					vis[pos-x]=1;
					num[pos-x]=0;
					return 1;
				}else return 0;
			}vis[pos-x]=vis[pos+x]=1;
			num[pos-x]=num[pos+x]=0;
			return 1;
		}else if(pos>x){
			if(vis[pos-x]){
				if(num[pos-x]==0)return 1;
				return 0;
			}else{
				num[pos-x]=0;
				vis[pos-x]=1;
				return 1;
			}
		}else if(pos+x<=n){
			if(vis[pos+x]){
				if(num[pos+x]==0)return 1;
				return 0;
			}else{
				num[pos+x]=0;
				vis[pos+x]=1;
				return 1;
			}
		}else return 1;
	}
}
int main(){
    cin>>t;
    while(t--){
    	cin>>s>>x;op=0;
    	n=s.size();
    	s.insert(0,"#");
    	F(i,1,n)vis[i]=num[i]=0;
    	F(i,1,n){
    		if(ok(i));
    		else{
    			cout<<-1<<endl;
    			op=1;break;
			}
		}if(op==0){
			F(i,1,n)putchar(num[i]+'0');
			putchar('\n');
		}
	}
    return 0;
}