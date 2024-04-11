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
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > P,Q,p,q;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        p.push_back(MP(a,b));
    }
    // sort(P.begin(),P.end());
    // rep(i,n){
    //     if(i==0){
    //         p.push_back(P[i]);
    //     }else{
    //         while(p.size()!=0 && p.back().second < P[i].second){
    //             p.pop_back();
    //         }
    //         p.push_back(P[i]);
    //     }
    // }
     n = p.size();
    rep(i,m){
        int a,b;
        cin >> a >> b;
        Q.push_back(MP(a,b));
    }
    sort(Q.begin(),Q.end());
    rep(i,m){
        if(i==0){
            q.push_back(Q[i]);
        }else{
            while(q.size()!=0 && q.back().second < Q[i].second){
                q.pop_back();
            }
            q.push_back(Q[i]);
        }
    }
    m = q.size();
    swap(p,q);
    swap(n,m);
    int mi = inf;
    set<pair<int,int>,greater<pair<int,int>>> st;
    vector<int> pre(m);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    rep(i,m){
        int nxt = lower_bound(all(p),q[i]) - p.begin();
        if(nxt!=n){
            int A = p[nxt].first;
            int B = p[nxt].second;
            if(B < q[i].second)continue;
            st.insert({B-q[i].second+1,i});
            pre[i] = B-q[i].second+1;
            pq.push({A-q[i].first+1,i});
        }
    }
    if(pq.size()==0)mi = 0;
    else{
        int tmp = 0;
        auto XXX = st.begin();
        chmin(mi,(*XXX).first);
        while(!pq.empty()){
            auto X = pq.top();
            pq.pop();
            int id = X.second;
            int diff = X.first;
            tmp = diff;
            st.erase(MP(pre[id],id));
            
            int nxtA = q[id].first + diff;
            int nxt = lower_bound(all(p),MP(nxtA,q[id].second)) - p.begin();
            if(nxt!=n){
                int A = p[nxt].first;
                int B = p[nxt].second;
                if(B < q[id].second){

                }else{
                    st.insert({B-q[id].second+1,id});
                    pre[id] = B-q[id].second+1;
                    pq.push({A-q[id].first+1,id});
                }
            }
            auto XX = st.begin();
            if(XX!=st.end()){
                chmin(mi,tmp + (*XX).first);
            }else{
                chmin(mi,tmp);
            }
        }
    }
    cout << mi << endl;
    return 0;
}