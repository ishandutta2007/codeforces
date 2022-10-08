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



int main() {
int st;

    scanf("%d",&st);
    Rep(t,st){
        int m,n,x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&m,&n,&x1,&y1,&x2,&y2);
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        long long lx = m - (x2-x1);
        long long ly = n - (y2-y1);
        long long res = 0;
        res = (long long)lx * ly;
        res *= 2;
        if(2 * lx > m && 2 * ly > n)
            res -= (2*lx-m)*(2*ly-n);
        res = (long long)m * n - res;
        cout<<res<<endl;
    }   

    return 0;   

}