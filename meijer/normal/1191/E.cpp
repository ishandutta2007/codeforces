#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef complex<double> vec;
#define X real()
#define Y imag()
#define INF 1e9
#define EPS 1e-9
#define PI 2*acos(0)
#define REP(i, a, b) for(int i = int(a); i != int(b); i++)

int n, k;
char chr;
bitset<100005> up;
bitset<100005> allLeftSame;
bitset<100005> allRightSame;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    REP(i,0,n) cin>>chr, up[i] = chr=='1';
    allLeftSame.reset();
    allLeftSame[0] = allLeftSame[1] = 1;
    REP(i,1,n)
        allLeftSame[i+1] = allLeftSame[i] && up[i] == up[i-1];
    allRightSame.reset();
    allRightSame[0] = allRightSame[1] = 1;
    REP(i,1,n)
        allRightSame[i+1] = allRightSame[i] && up[n-i] == up[n-i-1];
    if(allLeftSame[n-k] || allRightSame[n-k]) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    if(up[0] == up[n-1])
    REP(i,1,n-k) {
        if(allLeftSame[i] && allRightSame[n-i-k]) {
            cout << "tokitsukaze" << endl;
            return 0;
        }
    }
    if(k == n-1) cout << "quailty" << endl;
    else if(k*2 >= n) {
        if(up[0] != up[n-1]) {
            REP(i,1,n-k) {
                if(!allLeftSame[i] || !allRightSame[n-i-k]) {
                    cout<<"once again"<<endl;
                    return 0;
                }
            }
            cout << "quailty" << endl;
            return 0;
        }
    }
    cout<<"once again"<<endl;
}