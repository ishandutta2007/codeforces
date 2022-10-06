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
    int n;
    cin >> n;
    vector<pair<int,int> > p[2];
    rep(i,n){
        rep(j,n){
            p[(i+j)%2].push_back(MP(i+1,j+1));
        }
    }
    rep(i,n*n){
        int a;
        cin >> a;
        if(a==1){
            if(!p[1].empty()){
                auto x = p[1].back();
                p[1].pop_back();
                cout << 2 << " " << x.first << " " << x.second << endl;
            }else{
                auto x = p[0].back();
                p[0].pop_back();
                cout << 3 << " " << x.first << " " << x.second << endl;
            }
        }else if(a==2){
            if(!p[0].empty()){
                auto x = p[0].back();
                p[0].pop_back();
                cout << 1 << " " << x.first << " " << x.second << endl;
            }else{
                auto x = p[1].back();
                p[1].pop_back();
                cout << 3 << " " << x.first << " " << x.second << endl;
            }
        }else{
            if(!p[0].empty()){
                auto x = p[0].back();
                p[0].pop_back();
                cout << 1 << " " << x.first << " " << x.second << endl;
            }else{
                auto x = p[1].back();
                p[1].pop_back();
                cout << 2 << " " << x.first << " " << x.second << endl;
            }
        }
    }
    return 0;
}