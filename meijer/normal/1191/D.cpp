#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>
#include <map>

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

map<int, int> cnt;
ll n, temp, a[100005];
ll finishState, tot;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>temp, a[i]=temp, finishState+=i, tot+=temp, cnt[temp] = 0;
    int dup = 0, dupNumber = 0;
    REP(i,0,n) {
        if(cnt[a[i]] != 0) {
            dup++;
            dupNumber = a[i];
        }
        cnt[a[i]]++;
    }
    if(dup > 1 || (dup == 1 && dupNumber == 0)) {
        cout << "cslnb" << endl;
        return 0;
    }
    if(dup == 1) {
        REP(i,0,n) {
            if(a[i] == dupNumber-1) {
                cout << "cslnb" << endl;
                return 0;
            }
        }
    }
    if((tot-finishState)%2) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
}