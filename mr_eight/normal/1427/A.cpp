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
}vector<int>x1,x2;
int T,n,temp,m,tot1,tot2;
int main(){
    cin>>T;
    while(T--){
    	cin>>n;
    	m=0;tot1=tot2=0;
    	x1.clear(),x2.clear();
    	F(i,1,n){
    		temp=read();
    		
    		if(temp==0)m++;
    		else if(temp>0){
    			x2.push_back(temp);tot2+=temp;
			}else{tot1-=temp;
				x1.push_back(temp);
			}
		}if(tot1>tot2){
			printf("YES\n");
			
			F(i,0,x1.size()-1)printf("%d ",x1[i]);
			F(i,0,x2.size()-1)printf("%d ",x2[i]);
			F(i,1,m)printf("0 ");
			printf("\n");
		}else if(tot2>tot1){
			printf("YES\n");
			F(i,0,x2.size()-1)printf("%d ",x2[i]);
			F(i,0,x1.size()-1)printf("%d ",x1[i]);
			
			F(i,1,m)printf("0 ");printf("\n");
		}else printf("NO\n");
	}
    return 0;
}