#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;
const int K = 1e7;
const int N = 1e6 + 1;

int dsu[N];
int rang[N];


set <pair <int, int> > st1, st2;
int myfree = 1;

int pred(int a) {
    if(a == dsu[a]) return a;
    else return dsu[a] = pred(dsu[a]);
}

int sum = 0;
void unite(int a, int b){
    a = pred(a);
    b = pred(b);
    if(a == b){
        myfree++;
        return;
    }
    int fl = 0;
    auto it1a = st2.lower_bound({rang[a], a});
    auto it1b = st2.lower_bound({rang[b], b});
    if (it1a != st2.end() && *it1a == make_pair(rang[a], a)) {
        sum -= rang[a];
        fl++;
    }
    if (it1b != st2.end() && *it1b == make_pair(rang[b], b)) {
        sum -= rang[b];
        fl++;
    }
    st1.erase({rang[a], a});
    st1.erase({rang[b], b});
    st2.erase({rang[a], a});
    st2.erase({rang[b], b});
    if (rang[a] < rang[b]) {
        swap(a, b);
    }
    dsu[b] = a;
    rang[a] = rang[a] + rang[b]; 
    if(fl == 2){
        myfree++;
    }
    if (fl) {
        sum += rang[a];
        st2.insert({rang[a], a});
    }
    else {
        if(sz(st2)){
            sum -= st2.begin() -> x;
            st1.insert(*st2.begin());
            st2.erase(*st2.begin());
            myfree++;
        }
        st1.insert({rang[a], a});
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        dsu[i] = i;
        rang[i] = 1;
        st1.insert({1, i});
    }
    for(int i = 0; i < d; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
     //   cout << myfree << " ";
        while(myfree  > 0&& sz(st1)){
            pair <int, int> value = *st1.rbegin();
            sum += value.x;
            st1.erase(value);
            st2.insert(value);
            myfree--;
        }/*
        for(auto v : st2){
            cout << v.x << " " << v.y << " ";
        }*/
        cout << sum - 1 << "\n";
    }
    return 0;
}