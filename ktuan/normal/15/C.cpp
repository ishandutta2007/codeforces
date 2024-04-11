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

long long get(long long x){
    long long res = 0;
    Rep(i,62) {
        // i set to 1
        if((x & (1LL<<i))!=0) {
            long long sl = (x >> (i+1)) * (1LL<<i) + (x&((1LL<<i)-1))+1;
            if(sl % 2 != 0) res |= 1LL<<i;
        }
        else {
            long long sl = (x >> (i+1)) * (1LL<<i);
            if(sl % 2 != 0) res |= 1LL << i;
        }
    }
    return res;
}



int main() {
    //cout << get(6) << endl;
    int n;

    scanf("%d",&n);
    long long res = 0;
    Rep(i,n){
        long long m,x;
        scanf("%I64d%I64d",&x,&m);
        // cin>>m>>x;
        // if(x<1||m<1)while(1);
        long long r = get(x-1);
        r = r ^ get(m + x - 1);
        res ^= r;
    }   
    if(res!=0) cout << "tolik" << endl;
    else cout << "bolik" << endl;

    return 0;   

}