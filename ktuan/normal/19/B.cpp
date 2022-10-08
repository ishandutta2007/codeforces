#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int n;
PII a[2020];
long long F[2020][2040];

long long go(int i,int sum){
    if(sum>=n)return 0;
    if(i==n)return 1000000000000000LL;
    long long &ret=F[i][sum];
    if(ret!=-1)return ret;
    ret=1000000000000000LL;
    // chon i
    ret = min(ret,go(i+1,sum+a[i].fi+1)+a[i].se);
    ret = min(ret,go(i+1,sum));
    return ret;
}

int main() {
    cin>>n;
    Rep(i,n)cin>>a[i].fi>>a[i].se;
    memset(F,-1,sizeof(F));
    long long res=go(0,0);
    cout<<res<<endl;
    return 0;
}