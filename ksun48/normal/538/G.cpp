#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define LL2 __int128
typedef long long LL2;

LL fl(LL a, LL r){
    if(a % r == 0) return a/r;
    if(a > 0) return a/r;
    if(a < 0) return (-((-a)/r)-1);
}

LL cl(LL a, LL r){
    if(a % r == 0) return a/r;
    return fl(a,r) + 1;
}

int main(){
    LL n, l;
    scanf("%lld%lld", &n, &l);
    vector<LL> st(n+1), sx(n+1), sy(n+1);
    st[0] = sx[0] = sy[0] = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld%lld%lld", &st[i+1], &sx[i+1], &sy[i+1]);
        if((st[i+1] + sx[i+1] + sy[i+1]) % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
        if(abs(sx[i+1]) + abs(sy[i+1]) > st[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    vector<pair<LL,LL> > tlist;
    for(int i = 0; i < st.size(); i++){
        tlist.push_back(make_pair(st[i] % l, i)); 
    }
    sort(tlist.begin(), tlist.end());
    vector<LL> t, x, y, r;
    for(int i = 0; i < tlist.size(); i++){
        int a = tlist[i].second;
        t.push_back(st[a] % l);
        x.push_back(sx[a]);
        y.push_back(sy[a]);
        r.push_back(- (st[a]/l));
    }
    t.push_back(l); x.push_back(0); y.push_back(0); r.push_back(1);
    LL2 pmin = -l*2;
    LL2 pmax = l*2;
    LL2 qmin = -l*2;
    LL2 qmax = l*2;
    int ok = 1;
    for(int i = 0; i + 1 < t.size(); i++){
        LL2 dx = x[i+1] - x[i];
        LL2 dy = y[i+1] - y[i];
        LL2 dt = t[i+1] - t[i];
        LL2 dr = r[i+1] - r[i];
        if(dr == 0){
            if(abs((LL)dx) + abs((LL)dy) > dt) ok = 0;
            continue;
        }
        if(dr < 0){
            dr = -dr;
            dx = -dx;
            dy = -dy;
        }
        while(pmax >= pmin && pmax > fl(dt - dx - dy, dr) ) pmax--;
        while(pmax >= pmin && pmin < cl(-dt - dx - dy, dr) ) pmin++;
        while(qmax >= qmin && qmax > fl(dt - dx + dy, dr) ) qmax--;
        while(qmax >= qmin && qmin < cl(-dt - dx + dy, dr) ) qmin++;
    }
    while((pmin + l) % 2 != 0) pmin++;
    while((qmin + l) % 2 != 0) qmin++;
    while((pmax + l) % 2 != 0) pmax--;
    while((qmax + l) % 2 != 0) qmax--;
    if(pmin > pmax || qmin > qmax || !ok){
        cout << "NO" << endl;
        return 0;
    }
    LL c = (pmin + qmin)/2;
    LL d = (pmin - qmin)/2;
    for(int i = 0; i < t.size(); i++){
        x[i] += r[i] * c;
        y[i] += r[i] * d;
    }
    string ans;
    for(int i = 0; i + 1 < t.size(); i++){
        LL dt = t[i+1] - t[i];
        LL dx = x[i+1] - x[i];
        LL dy = y[i+1] - y[i];
        dt -= (abs(dx)) + (abs(dy));
        if(dy > 0) for(LL z = 0; z < dy; z++) ans += 'U';
        if(dy < 0) for(LL z = 0; z < -dy; z++) ans += 'D';
        if(dx > 0) for(LL z = 0; z < dx; z++) ans += 'R';
        if(dx < 0) for(LL z = 0; z < -dx; z++) ans += 'L';
        for(int j = 0; 2*j < dt; j++) ans += "DU";
    }
    cout << ans << endl;
}