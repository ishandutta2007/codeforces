#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n, od, ev, odc, evc, arr[110][110], mev, mod;
vector<pii> odvc, evvc;

void put_od_num(int val){
    arr[odvc.back().F][odvc.back().S]=val;
    printf("%d %d %d\n", val, odvc.back().F, odvc.back().S);
    odvc.pop_back();
    fflush(stdout);
}
void put_ev_num(int val){
    arr[evvc.back().F][evvc.back().S]=val;
    printf("%d %d %d\n", val, evvc.back().F, evvc.back().S);
    evvc.pop_back();
    fflush(stdout);
}

void solve(){
    int col;
    scanf("%d", &col);
    if(ev==0){
        for(int i=1; i<=3; i++){
            if(i!=col){
                evc=i;
                break;
            }
        }
        ev++;
        put_ev_num(evc);
    }
    else if(evc!=col){
        if(ev<mev){
            ev++;
            put_ev_num(evc);
        }
        else{
            int nc;
            for(int i=1; i<=3; i++){
                if(i!=col&&i!=evc){
                    nc=i;
                    break;
                }
            }
            od++;
            put_od_num(nc);
        }
    }
    else{
        if(od==0){
            for(int i=1; i<=3; i++){
                if(i!=col&&i!=evc){
                    odc=i;
                    break;
                }
            }
            od++;
            put_od_num(odc);
        }
        else if(od<mod){
            od++;
            put_od_num(odc);
        }
        else{
            int nc;
            for(int i=1; i<=3; i++){
                if(i!=odc&&i!=evc){
                    nc=i;
                    break;
                }
            }
            ev++;
            put_ev_num(nc);
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i+j)%2)odvc.eb(i, j);
            else evvc.eb(i, j);
        }
    }
    mev=(n*n+1)/2;
    mod=n*n-mev;
    for(int i=1; i<=n*n; i++)solve();
}