#include<bits/stdc++.h>
//#include<atcoder/all>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace atcoder;
//using namespace boost::multiprecision;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const ll mod=998244353;
const ll LINF=1ll<<60;
const int INF=1<<30;
int dx[]={0,1,0,-1,0,1,-1,1,-1};
int dy[]={0,0,1,0,-1,1,-1,-1,1};



int main(){
    int n, m;cin >> n >> m;
    vector<int> s(m), h(m);
    vector<int> H(n, 0);
    vector<int> id(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> h[i];
        s[i]--;
        id[s[i]] = i + 1;
        H[s[i]] = h[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int R = 0; R < n; R++) {
        { //
            stack<int> st;
            vector<int> ans;
            vector<bool> vis(n, false);
            for (int i = R; i < n; i++) {
                if(H[i]){
                    st.push(i);
                    int hp = H[i];
                    bool f = true;
                    for (int j = i; j >= R; j--) {
                        if(not vis[j]) hp += a[j];
                        if(hp < 0){
                            f = false;
                            break;
                        }
                    }
                    if(f){
                        for (int j = i; j >= R; j--) {
                            vis[j] = true;
                        }
                        while(not st.empty()){
                            ans.pb(id[st.top()]);
                            st.pop();
                        }
                    }
                }
            }
            if(st.empty()){
                for (int i = R - 1; i >= 0; i--) {
                    if(H[i]){
                        st.push(i);
                        int hp = H[i];
                        bool f = true;
                        for (int j = i; j <= R; j++) {
                            if(not vis[j]) hp += a[j];
                            if(hp < 0){
                                f = false;
                                break;
                            }
                        }
                        if(f){
                            for (int j = i; j <= R; j++) {
                                vis[j] = true;
                            }
                            while(not st.empty()){
                                ans.pb(id[st.top()]);
                                st.pop();
                            }
                        }
                    }
                }
                if(st.empty()){
                    assert(ans.size() == m);
                    cout << R + 1 << endl;
                    for (int i = 0; i < m; i++) {
                        cout << ans[i] << (i + 1 == m ? "\n" : " ");
                    }
                    return 0;
                }
            }
        }

        { //
            stack<int> st;
            vector<int> ans;
            vector<bool> vis(n, false);
            for (int i = R; i >= 0; i--) {
                if(H[i]){
                    st.push(i);
                    int hp = H[i];
                    bool f = true;
                    for (int j = i; j <= R; j++) {
                        if(not vis[j]) hp += a[j];
                        if(hp < 0){
                            f = false;
                            break;
                        }
                    }
                    if(f){
                        for (int j = i; j <= R; j++) {
                            vis[j] = true;
                        }
                        while(not st.empty()){
                            ans.pb(id[st.top()]);
                            st.pop();
                        }
                    }
                }
            }
            if(st.empty()){
                for (int i = R + 1; i < n; i++) {
                    if(H[i]){
                        st.push(i);
                        int hp = H[i];
                        bool f = true;
                        for (int j = i; j >= R; j--) {
                            if(not vis[j]) hp += a[j];
                            if(hp < 0){
                                f = false;
                                break;
                            }
                        }
                        if(f){
                            for (int j = i; j >= R; j--) {
                                vis[j] = true;
                            }
                            while(not st.empty()){
                                ans.pb(id[st.top()]);
                                st.pop();
                            }
                        }
                    }
                }
                if(st.empty()){
                    assert(ans.size() == m);
                    cout << R + 1 << endl;
                    for (int i = 0; i < m; i++) {
                        cout << ans[i] << (i + 1 == m ? "\n" : " ");
                    }
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}