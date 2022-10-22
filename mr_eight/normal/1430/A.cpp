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
}int t,n,temp;
int main(){
    cin>>t;
    while(t--){
    	cin>>n;temp=0;
    	while(n>15)n-=3,temp++;
    	if(n==1)printf("-1\n");
    	if(n==2)printf("-1\n");
    	if(n==3)printf("1 0 0\n");
    	if(n==4)printf("-1\n");
    	if(n==5)printf("0 1 0\n");
    	if(n==6)printf("2 0 0\n");
    	if(n==7)printf("0 0 1\n");
    	if(n==8)printf("1 1 0\n");
    	if(n==9)printf("3 0 0\n");
    	if(n==10)printf("0 2 0\n");
    	if(n==11)printf("2 1 0\n");
    	if(n==12)printf("4 0 0\n");
    	if(n==13)printf("%d 0 1\n",2+temp);
    	if(n==14)printf("%d 0 2\n",temp);
    	if(n==15)printf("%d 0 0\n",5+temp);
	}
    return 0;
}