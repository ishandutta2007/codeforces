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


void manacher(const string& S,vector<int>& res)
{
    int sz = (int)S.size(), i = 0, j = 0, k;
    res.resize(sz);
    while(i < sz){
        while(i-j >= 0 && i+j < sz && S[i-j] == S[i+j]) j++;
        res[i] = j, k = 1;
        while(i-k >= 0 && i+k < sz && k+res[i-k] < j){
            res[i+k] = res[i-k], k++;
        }
        i += k; j -= k;
    }
}


int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    rep(zz,T){
        string s;
        cin >> s;
        int n = s.size();
        int L = 0;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-1-i]){
                L++;
            }else{
                break;
            }
        }
        if(L==n/2){
            cout << s << "\n";
            continue;
        }
        string f;
        rep(i,L){
            f.push_back(s[i]);
        }
        string g = f;
        reverse(all(g));
        string t;
        for(int i=L;i<=n-1-L;i++){
            t.push_back(s[i]);
            if(i!=n-1-L){
                t.push_back('&');
            }
        }
        vector<int> res;
        manacher(t,res);
        int m = t.size();
        int mx = 0;
        int id = 0;
        rep(i,m){
            if(i-res[i]==-1||res[i]+i==m){
                if(chmax(mx,res[i])){
                    id = i;
                }
            }
        }
        string h;
        if(id-res[id]==-1){
            for(int i=0;i<=2*id;i+=2){
                h.push_back(t[i]);
            }
        }else{
            for(int i=m-1;i>=2*id-m+1;i-=2){
                h.push_back(t[i]);
            }
        }
        // cerr << f << " " << h << " " << g << endl;
        cout << f + h + g << "\n";
    }
    return 0;
}