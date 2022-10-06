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
    int n,m;
    ll s;
    cin >> m >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    vector<ll> c(m);
    rep(i,m){
        cin >> c[i];
    }
    
    vector<pair<int,int> >ppp;
    vector<int> aid(n);
    rep(i,n){
        ppp.push_back({a[i],i});
    }
    sort(all(a));
    reverse(all(a));
    sort(all(ppp));
    reverse(all(ppp));
    rep(i,n)aid[i] = ppp[i].second;
    vector<tuple<int,ll,int>>p;
    rep(i,m){
        p.push_back(make_tuple(b[i],c[i],i+1));
    }
    sort(all(p));
    reverse(all(p));
    int ok = n+1;
    int ng = 0;
    vector<int> res;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        ll T = 0;
        int id =0;
        int pid = 0;
        bool flag = 0;
        vector<int> tmp(n);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> > pq;
        while(id<n){
            while(pid<m){
                auto [B,C,ID] = p[pid]; 
                if(B >= a[id]){
                    pq.push(MP(C,ID));
                    pid++;
                }else{
                    break;
                }
            }
            if(!pq.empty()){
                auto [C,ID] = pq.top();
                T += C;
                pq.pop();
                for(int c=0;c<mid;c++){
                    if(id==n)break;
                    tmp[aid[id]] = ID;
                    id++;
                }
                continue;
            }else{
                flag = 1;
                break;
            }
        }
        if(flag||s<T){
            ng = mid;
        }else{ 
            ok = mid;
            res = tmp;
        }
    }
    if(ok > n){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    rep(i,n){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}