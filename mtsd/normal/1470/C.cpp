#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;
    if(n<=660){
        rep(i,330){
            cout << "? 1" << endl;
            int z;
            cin >> z;
        }
        vector<int> a(n);
        rep(i,n){

            cout << "? " << i+1 << endl;
            int z;
            cin >> z;
            if(z>k){
                a[i] = 1;
            }else if(z==k){
                a[i] = 0;
            }else{
                a[i] = -1;
            }
        }
        int res = 0;
        rep(i,n){
            if(a[(i+n-1)%n]<0&&a[i]==0&&a[(i+1)%n]>0){
                res = i+1;
            }
        }
        cout << "! " << res << endl;
        return 0;
    }else{
        rep(i,330){
            cout << "? 1" << endl;
            int z;
            cin >> z;
        }
        vector<int> a(n);
        int L,R;
        rep(i,320){

            cout << "? " << (i*320)%n + 1 << endl;
            int z;
            cin >> z;
            if(z>k){
                R = (i*320)%n + 1;
                L = (R+n-325)%n + 1;
                break;
            }
        }
        int res = 0;
        int id = L;
        while(id!=R){
            cout << "? " << id << endl;
            int z;
            cin >> z;
            if(z==k){
                res = id;
                break;
            }
            id++;
            if(id==n+1)id = 1;   
        }
        cout << "! " << res << endl;
    }
    return 0;
}