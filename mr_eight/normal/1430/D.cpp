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
}int t,n,l,r,cnt,now;
string s;
vector<int>v;
int main(){
    cin>>t;
    while(t--){
    	cin>>n>>s;v.clear();
    	v.push_back(1);
    	F(i,1,n-1){
    		if(s[i]==s[i-1])v[v.size()-1]++;
    		else v.push_back(1);
		}
    	l=0,r=v.size()-1;cnt=0;now=0;
    	while(l<=r){
    		cnt++;
    		while(now<=r){
    			if(v[now]<2)now++;
    			else break;
			}if(now>r){
				r--;
			}else{
				v[now]--;
			}l++;
			now=max(now,l);
		}cout<<cnt<<'\n';
	}
    return 0;
}