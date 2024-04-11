#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int a, b, c, d;
double ans;

typedef pair<double, double> Pd;

Pd RG(int a,int b,double x){
    vector <double> U, L;
    U.pb(a-x),U.pb(a+x);
    if(a-x < 0 && 0 < a+x)U.pb(0);
    L.pb(b-x),L.pb(b+x);
    if(b-x < 0 && 0 < b+x)L.pb(0);
    double MN = (a-x) * (b-x);
    double MX = MN;
    for(auto i : U){
        for(auto j : L){
            if(MN > i * j)MN = i * j;
            if(MX < i * j)MX = i * j;
        }
    }
    return Pd(MN, MX);
}

bool chk(double x){
    Pd p, q;
    p = RG(a, d, x);
    q = RG(b, c, x);
    if(p.Se >= q.Fi && q.Se >= p.Fi)return true;
    return false;
}

int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    double low = 0, high = 1e9, mid;
    for(int i=0;i<100;i++){
        mid = (low + high) / 2.0;
        if(chk(mid))ans = mid, high = mid;
        else low = mid;
    }
    printf("%.14f", ans);
    return 0;
}