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

#define MAXN 100007
typedef bitset<MAXN> vl;

//m - ilosc zmiennych, czyli tez indeks kolumny wyrazow wolnych
int gauss(vector<vl> a,vl& res,int m){//zwraca wymiar przestrzeni rozwiazan, -1 oznacza uklad sprzeczny
    int n=a.size();
    res.reset();
    vector<int> wyb(n,-1);
    REP(j,m){
        REP(i,n) if(a[i][j] && wyb[i] == -1){
            wyb[i]=j;
            REP(ii,n) if(i != ii && a[ii][j]) a[ii]^=a[i];
            break;
        }
    }
    int dim=m-n;
    REP(i,n) if(wyb[i] == -1){
        dim++;
        if(a[i][m]) return -1;
    }else res[wyb[i]]=a[i][m];
    return dim;
}

LL n,a[MAXN];
vl res, best;

int main(){
    ios_base::sync_with_stdio ( false );
    //in
    cin >> n;
    REP(i,n) cin >> a[i];
    //sol
    vector<vl> row;
    REP(q,2){
    FORD(p,62,0) {
        vl next;
        bool b = 0;
        REP(i,n) if(a[i]&(1LL << p)) {
            next[i] = 1;
            b = !b;
        }
        if(b != q) continue;
        next[n] = 1;
        row.PB(next);
        if(gauss(row, res, n) != -1) {
//            cout << "OK " << p << endl;
            best = res;
        } else
            row.pop_back();
    }
    }
    //out
    REP(i,n) cout << (best[i] ? 2 : 1) << " ";
    cout << endl;
    return 0;
}