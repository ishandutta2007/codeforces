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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int c = 1;
    int mx = 0;
    int ccc = 1;
    bool f = 1;
    vector<int> p;
    rep(i,n-1){
        if(f){
            if(a[i]<a[i+1]){
                c++;
            }else{
                p.push_back(c);
                c = 2;
                f = 0;
            }
        }else{
            if(a[i]>a[i+1]){
                c++;
            }else{
                p.push_back(c);
                c = 2;
                f = 1;
            }
        }
    }
    p.push_back(c);
    // for(auto x:p){
    //     cerr << x << " ";
    // }
    // cerr << endl;
    int m = p.size();
    if(m==1){
        cout << 0 << endl;
        return 0;
    }
    mx = 0;
    int C = 1;
    vector<int> id;
    rep(i,m){
        if(mx==p[i]){
            C++;
            id.push_back(i);
        }
        if(chmax(mx,p[i])){
            C = 1;
            id.clear();
            id.push_back(i);
        }
    }
    // cerr << C << endl;
    if(C!=2){
        cout << 0 << endl;
    }else{
        if(abs(id[0]-id[1])==1){
            if(id[0]%2==0&&mx%2==1){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}