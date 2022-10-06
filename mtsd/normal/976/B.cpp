#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>

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
    ll n,m,k;
    cin >> n >> m >> k;
    if(k<=n-1){
        cout << k+1 << " " << 1 << endl;
    }else{
        k -= n;
        ll a,b;
        a = k/(m-1);
        b = k%(m-1);
        if(a%2==0){
            cout << n-a << " " << 2+b << endl;
        }else{
            cout << n-a << " " << m-b << endl;
        }
    }


    return 0;
}