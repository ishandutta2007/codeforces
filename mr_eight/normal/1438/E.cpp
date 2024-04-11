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
#include<tr1/unordered_map>
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
int a[200002],sum[200002],n;
ll ans;
tr1::unordered_map<ll,bool>mp;
int main(){
    cin>>n;
    F(i,1,n)read(a[i]),sum[i]=sum[i-1]+a[i];
    F(i,1,n){
        F(j,i+2,n){
            if(floor(log2(sum[j-1]-sum[i]))>floor(log2(a[i])))break;
            
            if(sum[j-1]-sum[i]==(a[i]^a[j])){
                ans++;
                mp[i*1000000000ll+j]=1;
            }
        }
    }F(i,1,n){
        UF(j,i-2,1){
            if(floor(log2(sum[i-1]-sum[j]))>floor(log2(a[i])))break;
            if(sum[i-1]-sum[j]==(a[i]^a[j])&&(!mp[j*1000000000ll+i])){
                ans++;
            }
        }
    }cout<<ans;
    return 0;
}