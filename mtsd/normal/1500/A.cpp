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
pair<int,int> S[6000000];
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    Fill(S,MP(-1,-1));
    rep(i,n){
        rep(j,i){
            if(S[a[i]+a[j]].first!=-1){
                int x,y;
                x = S[a[i]+a[j]].first;
                y = S[a[i]+a[j]].second;
                if(x==i||x==j||y==i||y==j)continue;
                cout << "YES\n";
                cout << x+1 << " " << y+1 << " " << i+1 << " " << j+1 << "\n";
                return 0;
            }else{
                S[a[i]+a[j]] = MP(i,j);
            }
        }
    }

    cout << "NO\n";
    return 0;
}