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
int n,m,a[102][102],t;
int orz[100002],cnt;
int main(){
    cin>>t;
    while(t--){cnt=0;
    	cin>>n>>m;
    	F(i,1,n)F(j,1,m)a[i][j]=read(),orz[++cnt]=a[i][j],orz[++cnt]=a[i][j]+1;
    	sort(orz+1,orz+cnt+1);
    	F(qwq,1,cnt){
    		F(i,1,n){
    			F(j,1,m){
    				if(a[i][j]==orz[qwq]&&((i+j)&1)==(orz[qwq]&1))a[i][j]++;
				}
			}
		}F(i,1,n){
			F(j,1,m){
				cout<<a[i][j]<<' ';
			}cout<<'\n';
		}
	}
    return 0;
}