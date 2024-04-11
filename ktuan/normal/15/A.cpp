#include <iostream>

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


PII a[1111];
int n,t;


int main() {

    cin>>n>>t;
    Rep(i,n){
        cin>>a[i].fi>>a[i].se;
    }
    sort(a,a+n);
    int res=2;
    Rep(i,n-1){
        int dist=a[i+1].fi-a[i].fi;
        if(dist*2 == a[i].se+a[i+1].se+2*t)++res;
        else if(dist*2 > a[i].se+a[i+1].se+2*t)res+=2;
    }
    cout<<res<<endl;

    return 0;   

}