#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

set<pair<pair<int, int>, int> > pcs;

int l[1010101];
int u[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    int i2=2;
    pcs.insert({{1, n}, 1});
    pcs.insert({{n+1, n+2}, 1});
    for (int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        char s;
        cin>>s;
        auto it=pcs.lower_bound({{x, n+3}, 0});
        it--;
        auto t=*it;
        if (t.F.F>x||t.F.S<x){
            cout<<"0\n";
        }
        else{
            if (s=='L'){
                cout<<x-l[t.S]<<'\n';
            }
            else{
                cout<<y-u[t.S]<<'\n';
            }
            pcs.erase(it);
            if (x>t.F.F){
                l[i2]=l[t.S];
                u[i2]=u[t.S];
                if (s=='L'){
                    u[i2]=y;
                }
                pcs.insert({{t.F.F, x-1}, i2++});
            }
            if (x<t.F.S){
                l[i2]=l[t.S];
                u[i2]=u[t.S];
                if (s=='U'){
                    l[i2]=x;
                }
                pcs.insert({{x+1, t.F.S}, i2++});
            }
        }
    }
}