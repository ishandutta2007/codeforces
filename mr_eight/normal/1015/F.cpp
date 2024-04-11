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
namespace fastIO {
    template<class T>
    inline void read(T &x) {
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
    template<class T,class... Args>
    inline void read(T& t,Args&... args) {
        read(t);
        read(args...);
    }
    char _n_u_m_[40];
    template<class T>
    inline void write(T x ) {
        if(x==0){
            putchar('0');
            return;
        }
        T tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar('-') ;
        register int cnt = 0 ;
        while( tmp > 0 ) {
            _n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
    }
    template<class T>
    inline void write(T x ,char ch) {
        write(x);
        putchar(ch);
    }
}
using namespace fastIO;
#define mod 1000000007
int n,m,dp[202][202][202],f[202],x[202],y[202];
char s[202];
int main(){
    cin>>n;n<<=1;
    scanf("%s",s+1);
    m=strlen(s+1);
    f[0]=-1;
    F(i,1,m){
        int k=f[i-1];
        while(~k){
            if(s[k+1]==s[i]){
                f[i]=k+1;
                break;
            }
            k=f[k];
        }
    }
    F(i,0,m-1){
        x[i]=i+1;
        for(int k=f[i];~k;k=f[k]){
            if(s[k+1]!=s[i+1]){
                y[i]=k+1;
                break;
            }
        }
        if(s[i+1]==')')swap(x[i],y[i]);
    }
    x[m]=y[m]=m;
    dp[0][0][0]=1;
    F(i,0,n-1){
        F(j,0,i)F(k,0,i)if(dp[i][j][k]){
            if(k)(dp[i+1][y[j]][k-1]+=dp[i][j][k])%=mod;
            (dp[i+1][x[j]][k+1]+=dp[i][j][k])%=mod;//cerr<<i<<" "<<j<<" "<<k<<endl;
        }
    }
    cout<<dp[n][m][0];
    return 0;
}