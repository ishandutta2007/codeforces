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
    int n,m;
    cin >> n >> m;
    vector<string>s(n);
    rep(i,n)cin >> s[i];
    vector<int> a(m);
    rep(i,n){
        rep(j,m){
            if(s[i][j]=='1'){
                a[j]++;
            }
        }
    }
    bool flag = 0;
    rep(i,n){
        bool fflag = 1;
        rep(j,m){
            if(s[i][j]=='1'&&a[j]==1){
                fflag = 0;
            }
        }
        if(fflag){
            flag = 1;
        }
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}