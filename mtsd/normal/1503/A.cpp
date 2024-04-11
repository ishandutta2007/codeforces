#include <bits/stdc++.h>
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a,b;
        rep(i,n){
            if(s[i]=='1'){
                a.push_back(i);
            }else{
                b.push_back(i);
            }
        }
        if((int)b.size()%2!=0||(int)a.size()%2!=0){
            cout << "NO\n";
            continue;
        }
        vector<int>p(n),q(n);
        rep(i,a.size()){
            if(i<a.size()/2){
                p[a[i]] = 1;
                q[a[i]] = 1;
            }else{
                p[a[i]] = -1;
                q[a[i]] = -1;
            }
        }
        rep(i,b.size()){
            if(i%2==0){
                p[b[i]] = 1;
                q[b[i]] = -1;
            }else{
                p[b[i]] = -1;
                q[b[i]] = 1;
            }
        }
        int mi = 0;
        int P = 0,Q = 0;
        rep(i,n){
            P += p[i];
            Q += q[i];
            chmin(mi,P);
            chmin(mi,Q);
        }
        if(mi<0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            rep(i,n){
                if(p[i]==1)cout << "(";
                else cout << ")";
            }
            cout << "\n";
            rep(i,n){
                if(q[i]==1)cout << "(";
                else cout << ")";
            }
            cout << "\n";
        }
    }
    return 0;
}