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
}unsigned int T,n,a[100002],v;
void check(int pos){v=0;
	F(i,1,n){
		if(a[i]&(1<<pos))v++;
	}if(v%4==1){
		cout<<"WIN"<<endl;
		return;
	}if(n%2==0){
		cout<<"WIN"<<endl;
	}else{
		cout<<"LOSE"<<endl;
	}
}
int main(){
    cin>>T;
    while(T--){
    	n=read();
    	F(i,1,n)a[i]=read();
    	v=0;
    	F(i,1,n)v^=a[i];
    	UF(i,30,0){
    		if(v&(1<<i)){
    			check(i);
    			break;
			}if(i==0){
				cout<<"DRAW"<<endl;
			}
		}
	}
    return 0;
}