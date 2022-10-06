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
    string s;
    int a = 0;
    int b = 0;
    int n;
    bool f = 1;
    vector<char> c;
    while(cin >> s){
        if(s[0]=='?'){
            if(f){
                a++;
            }else{
                b++;
            }
        }else if(s[0]=='+'){
            c.push_back('+');
            f = 1;
        }else if(s[0]=='-'){
            c.push_back('-');
            f = 0;
        }else if(s[0]=='='){
            c.push_back('=');
        }else{
            n = stoi(s);
        }
    }
    if(n<= a*n-b && a*1-b*n <= n){
        cout << "Possible\n";
        vector<int> p(a,1),q(b,1);
        if(n >= a-b){
            rep(i,n-(a-b)){
                p[i%a]++;
            }
        }else{
            for(int i=0;i<(a-b)-n;i++){
                q[i%b]++;
            }   
        }
        int ida = 1;
        int idb = 0;
        cout << p[0] << " ";
        for(int i=0;i<c.size();i++){
            cout << c[i] << " ";
            if(c[i]=='+'){
                cout << p[ida] << " ";
                ida++;
            }else if(c[i]=='-'){
                cout << q[idb] << " ";
                idb++;
            }else{
                cout << n << "\n";
            }
        }
    }else{
        cout << "Impossible\n";
    }
    return 0;
}