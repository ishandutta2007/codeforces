#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n;
    cin >> n;
    vector<int> p(n/2);
    rep(i,n/2)cin >> p[i];
    sort(p.begin(),p.end());
    int a=0,b=0;
    rep(i,n/2){
        a += abs(p[i]-(i*2+1));
    }
    rep(i,n/2){
        b += abs(p[i]-(i*2+2));
    }
    cout << min(a,b) << endl;
    return 0;
}