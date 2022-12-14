#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <complex>
#include <queue>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin(); i != (x).end(); ++i)
#define ALL(x) x.begin(),(x).end()
#define SZ(x) ((x).size())
#define X first
#define Y second
#define CLR(x) memset((x),0,sizeof(x))
typedef long long int LL;
typedef long long unsigned int LLU;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;

int n,k;

VI odw(VI p){
    VI res(n,0);
    REP(i,n)
        res[p[i]] = i;
    return res;
}

VI mnoz(VI a,VI b){
    VI res(n,0);
    REP(i,n) res[i]=a[b[i]];
    return res;
}

VI in(){
    VI res(n,0);
    REP(i,n) cin >> res[i];
    REP(i,n) res[i]--;
    return res;
}

VI id(){
    VI res(n,0);
    REP(i,n) res[i]=i;
    return res;
}

int main(){
    ios_base::sync_with_stdio ( false );
    //in
    cin >> n >> k;
    VI a = in();
    VI b = in();
    bool res = false;
    if(b == id()) res = false;
    else if(odw(a) == a)
        res = (a == b && k == 1);
    else {
        REP(ewqewq,2){
        VI x = a;
        FOR(q,1,k) {
            if(x == b && q%2 == k%2) res = true;
            x = mnoz(x, a);
        }
        a=odw(a);
        }
    }
    //out
    cout << (res?"YES":"NO") << endl;
    return 0;
}