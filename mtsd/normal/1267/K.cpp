#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
ll fac[21];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int nn;
    cin >> nn;  
    fac[0] = 1;
    for(ll i=1;i<=20;i++){
        fac[i] = fac[i-1]*i;
    }
    rep(t,nn){
        ll a;
        cin >> a;
        if(a==1){
            cout << 0 << "\n";
            continue;
        }
        vector<ll> res;
        ll b = 2;
        while(a!=0){
            res.push_back(a%b);
            a /= b;
            b++;
        }
        sort(res.begin(),res.end());
        int n = res.size();
        vector<ll> s(24);
        vector<ll> q(24);
        
        sort(res.begin(),res.end());
        // for(auto x:res){
        //     cerr << x << " ";
        // }
        // cerr << endl;
        
        rep(i,n){
            s[res[i]]++;
            q[res[i]]++;
        }
        for(int i=1;i<=23;i++){
            s[i] += s[i-1];
        }
        ll p = 1;
        ll d = 2;
        while(d-2!=n){
            p *= (s[d-1]-d+2);
            d++;
            //cerr << p << " " << d << endl;
        }
        for(int i=0;i<=23;i++){
            if(q[i]!=0){
                p /=fac[q[i]];
            }
        }
        //cerr << p << endl;
        ll pp = 0;
        if(q[0]!=0){
            pp = 1;
            d = 2;
            while(d-2!=n-1){
                pp *= (s[d-1]-d+1);
                d++;
            }
            for(int i=0;i<=23;i++){
                if(q[i]!=0){
                    if(i==0&&q[i]>1){
                        pp /=fac[q[i]-1];
                    }else{
                        pp /=fac[q[i]];
                    }
                }
            }
        }
        cout << p - pp - 1 << "\n";
    }
    return 0;
}