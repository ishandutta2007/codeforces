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
int t,ans,ans2;string s;
bool rev[100002];
int main(){
    cin>>t;
    while(t--){memset(rev,0,sizeof(rev));read();
    	cin>>s;ans=ans2=0;
    	F(i,0,s.size()-1){
    		if(s[i]!='0'+(i%2)){
    			rev[i+1]=1;
			}
		}if(rev[1])ans++;else ans2++;
		F(i,2,s.size()){
			if(rev[i]&&(!rev[i-1]))ans++;
			if(!rev[i]&&(rev[i-1]))ans2++;
		}cout<<min(ans,ans2)<<endl;/*F(i,1,s.size())cout<<rev[i]<<endl;*/
	}
    return 0;
}