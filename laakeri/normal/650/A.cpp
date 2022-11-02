#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<int, ll> xp;
map<int, ll> yp;
map<pair<int, int>, ll> p;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll v=0;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v+=xp[x];
        v+=yp[y];
        v-=p[{x, y}];
        xp[x]++;
        yp[y]++;
        p[{x, y}]++;
    }
    cout<<v<<endl;
}