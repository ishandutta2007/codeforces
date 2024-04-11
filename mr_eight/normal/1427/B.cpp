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
}int t,n,k,cnt,now;
string s;
vector<int>qwq;
inline bool check(){
	F(i,1,n)if(s[i]=='W')return 0;
	return 1;
}
int main(){
    cin>>t;
    while(t--){
    	cin>>n>>k>>s;
    	s.insert(0,"#");
    	if(check()){
    		cout<<max(0,k*2-1)<<'\n';
    		continue;
		}
    	qwq.clear();
    	cnt=0;now=0;
    	F(i,1,s.size()-1)if(s[i]=='L')cnt++;
    	k=min(k,cnt);
    	F(i,1,n){
    		if(s[i]=='W'){
    			now++;
    			F(j,0,n-i-1){
    				if(s[i+j+1]=='W'){
    					qwq.push_back(j);
    					break;
					}
				}
			}
		}sort(qwq.begin(),qwq.end());
		now+=2*k;
		F(i,0,qwq.size()-1){
			if(k<qwq[i]){
				break;
			}else{
				k-=qwq[i];
				now++;
			}
		}printf("%d\n",now);
	}
    return 0;
}