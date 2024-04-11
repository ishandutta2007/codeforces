#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF = 2e9;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

bool merge(string &a, string &b, string &dest){
    For(i, a.size()){
        if (a[i] == b[0]){
            if (i + b.size() > a.size()){
                dest = a.substr(0, i) + b;
                return true;
            }
            dest = a;
            return true;
        }
    }
    For(i, b.size()){
        if (b[i] == a[0]){
            if (i + a.size() > b.size()){
                dest = b.substr(0, i) + a;
                return true;
            }
            dest = b;
            return true;
        }
    }
    return false;
}

string v[111];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    string ans = "";
    for (int counter = 0; counter < 105; ++counter){
        for (int i = 0; i < n; ++i) {
            if (v[i].size() > 0) {
                for (int j = 0; j < n; ++j) {
                    if (i != j){
                        if (merge(v[i], v[j], v[i])) v[j] = "";
                    }
                }
            }
        }
    }
    For(i, n){
        printf("%s", v[i].c_str());
    }
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}