#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <random>
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

long long  mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    bool flag = 0;
    for(int i=0;i<n;i++){
        int mx = -1;
        int t=-1;
        for(int j=0;j<a.size();j++){
            if(mx<a[j]){
                mx = a[j];
                t = j;
            }
            if(j!=0){
                if(abs(a[j]-a[j-1])>=2){
                    flag =1;
                }
            }
            if(flag)break;
        }
        a.erase(a.begin()+t);
        if(flag)break;
    }
    if(flag)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}