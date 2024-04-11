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
    int n;
    string s;
    cin >> n >> s;
    int tmp =0;
    rep(i,n){
        if(s[i]=='0')tmp++;
    }
    if(n==tmp){
        cout << s << endl;
    }else{
        cout << 1;
        rep(i,tmp)cout << 0;
        cout << endl;
    }

    return 0;
}