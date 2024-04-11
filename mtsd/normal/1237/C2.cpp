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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<pair<int,pair<int,int> > ,int> > a;
    rep(i,n){
        int b,c,d;
        cin >> b >> c >> d;
        a.push_back(MP(MP(b,MP(c,d)),i+1));
    }
    sort(a.begin(),a.end());
    set<pair<pair<int,int>,int> >st;
    pair<pair<int,int>,int> s = MP(MP(-inf,-inf),-1);
    int id = 0;
    vector<pair<int,int> > res;
    rep(i,n){
        if(i==0){
            s = MP(a[0].first.second,a[0].second);
            continue;
        }else{
            if(a[i].first.first==a[i-1].first.first){
                st.insert(MP(a[i].first.second,a[i].second));
                continue;
            }else{
                
                while(!st.empty()){
                    if(s.second==-1){
                        auto x = st.begin();
                        s = *x;
                        st.erase(x);
                    }else{
                        pair<pair<int,int>,int> p;
                        auto x = st.lower_bound(MP(MP(s.first.first,-inf),-1));
                        if(x!=st.end()){
                            auto y = st.lower_bound(MP(MP((*x).first.first,s.first.second),-1));
                            if(y==st.end()||(*y).first.first!=(*x).first.first){
                                y--;
                                p = (*y);
                            }else{
                                p = (*y);
                            }
                        }else{
                            x--;
                            auto y = st.lower_bound(MP(MP((*x).first.first,s.first.second),-1));
                            if(y==st.end()){
                                y--;
                                p = (*y);
                            }else{
                                p = (*y);
                            }
                        }
                        res.push_back(MP(s.second,p.second));
                        st.erase(p);
                        s = MP(MP(-inf,-inf),-1);
                    }
                }
                
                st.insert(MP(a[i].first.second,a[i].second));
            }
        }
    }
    while(!st.empty()){
        if(s.second==-1){
            auto x = st.begin();
            s = *x;
            st.erase(x);
        }else{
            pair<pair<int,int>,int> p;
            auto x = st.lower_bound(MP(MP(s.first.first,-inf),-1));
            if(x!=st.end()){
                auto y = st.lower_bound(MP(MP((*x).first.first,s.first.second),-1));
                if(y==st.end()||(*y).first.first!=(*x).first.first){
                    y--;
                    p = (*y);
                }else{
                    p = (*y);
                }
            }else{
                x--;
                auto y = st.lower_bound(MP(MP((*x).first.first,s.first.second),-1));
                if(y==st.end()){
                    y--;
                    p = (*y);
                }else{
                    p = (*y);
                }
            }
            res.push_back(MP(s.second,p.second));
            st.erase(p);
            s = MP(MP(-inf,-inf),-1);
        }
    }
    for(auto x:res){
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}