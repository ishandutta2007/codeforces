#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1200005;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;

int b[N];
vector<int> e, o;
set<int> in;

int sm[15000005];
int b1 = 0, b2 = 0;
void dfs(int n, int le, int bitmask = 0, int sum = 0){
    if(b1 || b2) return;
    if(n == 0){
        if(sm[sum] != 0){
            b1 = sm[sum];
            b2 = bitmask;
            return;
        }
        sm[sum] = bitmask;
        return;
    }
    if(le){
        dfs(n - 1, le - 1, bitmask | (1 << (n - 1)), sum + o[n - 1]);
    }
    if(n > le){
        dfs(n - 1, le, bitmask, sum);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>b[i];
        in.insert(b[i]);
        if(b[i] % 2 == 0) e.push_back(b[i]);
        else o.push_back(b[i]);
    }
    if((int)in.size() != n){
        cout<<"YES\n";
        for(int x : in) cout<<x<<' ';
        for(int i = in.size(); i < n; ++i) cout<<0<<' ';
        return 0;
    }

    if(e.size() >= 3 || (e.size() >= 1 && o.size() >= 2)){
        cout<<"YES\n";
        int a[3], s = 0;
        if(e.size() >= 3){
            for(int i = 0; i < 3; ++i){
                a[i] = e.back();
                e.pop_back();
            }
        } else {
            a[0] = e.back();
            e.pop_back();
            a[1] = o.back();
            o.pop_back();
            a[2] = o.back();
            o.pop_back();
        }
        s = (a[0] + a[1] + a[2]) / 2;
        for(int i = 0; i < 3; ++i)
            a[i] = s - a[i];
        for(int i = 0; i < 3; ++i)
            cout<<a[i]<<' ';
        while(!o.empty()){
            cout<<o.back() - a[0]<<' ';
            o.pop_back();
        }
        while(!e.empty()){
            cout<<e.back() - a[0]<<' ';
            e.pop_back();
        }
        return 0;
    }
    if(o.size() <= 1){
        cout<<"NO\n";
        return 0;
    }
    dfs(min((int)o.size(), 28), min((int)o.size() / 2, 14));
    if(b1 == 0){
        cout<<"NO\n";
        return 0;
    }

    int w = b1 & b2;
    b1 ^= w;
    b2 ^= w;
    cout<<"YES\n";
    cout<<0<<' ';
    int la = 0;
    int i1 = 0 ;
    int i2 = 0 ;
    while(b1){
        for(; i1 < 28; ++i1){
            if(b1 & (1 << i1)){
                la = o[i1] - la;
                cout<<la<<' ';
                o[i1] = 0;
                b1 ^= (1 << i1);
                break;
            }
        }
        if(!b1) break;
        for(; i2 < 28; ++i2){
            if(b2 & (1 << i2)){
                la = o[i2] - la;
                cout<<la<<' ';
                o[i2] = 0;
                b2 ^= (1 << i2);
                break;
            }
        }
    }
    for(;i2 < 28; ++i2){
        if(b2 & (1 << i2)){
            la = o[i2] - la;
            o[i2] = 0;
            b2 ^= (1 << i2);
            break;
        }
    }
    for(int x : o){
        if(x !=0) cout<<x<<' ';
    }
}