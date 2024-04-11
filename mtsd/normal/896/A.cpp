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
string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t = "What are you doing while sending \"";
string u = "\"? Are you busy? Will you send \"";
string v = "\"?";
ll len[100010];
char dfs(int id,ll k){
    if(id==0){
        return s[k];
    }
    if(k < t.size()){
        return t[k];
    }else if(k < (ll)t.size() + len[id-1]){
        return dfs(id-1,k-(ll)t.size());
    }else if(k < (ll)t.size() + len[id-1] + (ll)u.size()){
        return u[k -t.size() - len[id-1]];
    }else if(k < t.size() + len[id-1] + u.size() + len[id-1]){
        return dfs(id-1,k-(ll)(t.size() + len[id-1] + u.size()));
    }else{
        return v[k-(ll)t.size() - len[id-1] - (ll)u.size() - len[id-1]];
    }
}
int main(){
    int q;
    cin >> q;
    len[0] = s.size();
    for(int i=1;i<=100000;i++){
        len[i] = t.size() + len[i-1] + u.size() + len[i-1] + v.size();
        if(len[i]>1000000000000000000LL){
            len[i] = 1000000000000000001LL;
        }
    }
    rep(zz,q){
        int n;
        cin >> n;
        ll k;
        cin >> k;
        if(len[n] < k){
            cout << ".";
            continue;
        }
        k--;
        cout << dfs(n,k);
    }
    cout << endl;
    return 0;
}