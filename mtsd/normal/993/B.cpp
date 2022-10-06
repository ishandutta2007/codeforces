#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> >a(10),b(10);
    vector<pair<int,int> > v(n),u(m);
    rep(i,n){
        int x,y;
        cin >> x >>y;
        v[i] = MP(x,y);
        a[x].PB(y);
        a[y].PB(x);
    }
    rep(i,m){
        int x,y;
        cin >> x >>y;
        u[i] = MP(x,y);
        b[x].PB(y);
        b[y].PB(x);
    }
    bool fflag=0;
    int cnt1 = 0;
    set<int> ans1;
    for(int i=0;i<n;i++){
        int x = v[i].first;
        int y = v[i].second;
        bool flag1 = 0;
        for(auto z:b[x]){
            if(z==y){
                continue;
            }else{
                flag1 = 1;
            }
        }
        bool flag2 = 0;
        for(auto z:b[y]){
            if(z==x){
                continue;
            }else{
                flag2 = 1;
            }
        }
        if(flag1&flag2){
            fflag = 1;
        }else if(flag1||flag2){
            cnt1++;
            if(flag1){
                ans1.insert(x);
            }else{
                ans1.insert(y);
            }
        }
    }
    if(fflag){
        cout << -1 << endl;
        return 0;
    }
    int cnt2 = 0;
    set<int> ans2;
    for(int i=0;i<m;i++){
        int x = u[i].first;
        int y = u[i].second;
        bool flag1 = 0;
        for(auto z:a[x]){
            if(z==y){
                continue;
            }else{
                flag1 = 1;
            }
        }
        bool flag2 = 0;
        for(auto z:a[y]){
            if(z==x){
                continue;
            }else{
                flag2 = 1;
            }
        }
        if(flag1&flag2){
            fflag = 1;
        }else if(flag1||flag2){
            cnt2++;
            if(flag1){
                ans2.insert(x);
            }else{
                ans2.insert(y);
            }
        }
    }
    if(fflag){
        cout << -1 << endl;
        return 0;
    }
    if(ans1.size()>1&&ans2.size()>1){
        cout << 0 << endl;
    }else{
        if(ans1.size()==1){
            cout << *ans1.begin() << endl;
        }else if(ans2.size()==1){
            cout << *ans2.begin() << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}