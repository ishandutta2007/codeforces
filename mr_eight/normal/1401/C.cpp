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
}ll t,n,a[100002],mmin,last;
bool mark[100002];
vector<int>num;
inline bool check(){
	ri pos=0;
	last=0;
	F(i,1,n){
		if(mark[i]){
			if(num[pos]<last)return 0;
			last=num[pos++];
		}else{
			if(a[i]<last)return 0;
			last=a[i];
		}
	}return 1;
}
int main(){
 cin>>t;
 while(t--){
 	cin>>n;mmin=INT_MAX;
 	num.clear();
 	F(i,1,n)a[i]=read(),mmin=min(mmin,a[i]);
 	F(i,1,n){
 		if(a[i]%mmin==0)mark[i]=1,num.push_back(a[i]);
 		else mark[i]=0;
	}sort(num.begin(),num.end());
	if(check()){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
 }   
    return 0;
}