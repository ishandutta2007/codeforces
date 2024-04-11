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
}ll n,k,q,a[30][30],qr;
inline void gt(int i,int j,ll res,ll p){
	printf("%d %d\n",i,j);
	cout.flush();
	if(i<n){
		if((a[i+1][j]&res)||((a[i+1][j]==0)&&((res&(1ll<<(p+1)))==0))){
			gt(i+1,j,res-a[i+1][j],p+1);
			return;
		}
	}if(j<n){
		if((a[i][j+1]&res)||((a[i][j+1]==0)&&((res&(1ll<<(p+1)))==0))){
			gt(i,j+1,res-a[i][j+1],p+1);
			return;
		}
	}
}
int main(){
    cin>>n;
    F(i,2,2*n){
    	F(j,1,i-1){
    		
    		ri k=i-j;
    		if(k>n||j>n)continue;
    		if(j%2==0){
    			a[j][k]=(1ll<<((long long)(i-2)));
			}
		}
	}F(i,1,n){
		F(j,1,n){
			cout<<a[i][j]<<' ';
		}cout<<endl;
		cout.flush();
	}cin>>q;
	while(q--){
		cin>>k;
		gt(1,1,k,0);
	}
    return 0;
}