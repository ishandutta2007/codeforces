#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

void print_binary(ll x){
    for(int i=31;i>=0;i--) printf("%d",(x&(1<<i))?1:0);
    printf("\n");
}
ll pow2[20050];
int N;
char buf[10050];
ll to_ll(string s){
    ll sum = 0, t = 1;
    for(int i=sz(s)-1;i>=0;i--){
        sum += (s[i]-'0')*t;
        t *= 10;
    }
    return sum;
}
string tostring(ll X){
    if( X == 0 ) return "0";
    string res = "";
    while( X ){
        res += (char) ('0' + (X%10));
        X /= 10;
    }
    reverse(all(res));
    return res;
}
string ll_to_IP(ll x, ll k){
    string res = "";
    for(int base=24;base>=0;base-=8){
        ll tmp = 0;
        for(int i=0;i<8;i++){
            if( x&(1<<(base+i)) ) tmp += (1<<i);
        }
        res += tostring(tmp);
        res += ".";
    }
    res.pop_back();
    res += "/" + to_string(k);

    return res;
}
pair<int, pll> IP_to_range(string s){
    int sign = 1;
    if( s[0] == '-' ) sign = -1;
    bool flag = false;
    rep(i,sz(s)) if( s[i] == '/' ) flag = true;
    if( !flag ) s += "/32";

    vector<ll> v;
    string tmp = "";
    for(int i=1;i<sz(s);i++){
        if( s[i] == '.' || s[i] == '/' ){
            v.pb( to_ll(tmp.c_str()) );
            tmp = "";
        }  
        else tmp += s[i];
    }
    ll k = 32-to_ll(tmp);

    ll L = v[0] * pow2[24] + v[1] * pow2[16] + v[2] * pow2[8] + v[3];
    ll R;
    if( k == 0 ) return {sign, {L,L}};
    
    L &= ~((1<<k)-1);
    R = L | ((1<<k)-1);
    
    return {sign,{L,R}};
}


vector<ll> idx;
vector<pll> blist, wlist;
vector<string> ans;
int get_idx(ll X){
    return lower_bound(all(idx), X) - idx.begin() + 1;
}
ll tB[1000500], tW[1000500];
ll BS[1000500], WS[1000500];

void dfs(ll L, ll R, ll k ){
    int wcnt = 0, bcnt = 0;
    auto it = upper_bound(all(idx), R); it--;
    int i = it - idx.begin() + 1;

    wcnt = WS[i] - WS[get_idx(L)-1];
    bcnt = BS[i] - BS[get_idx(L)-1];
    //printf("[%lld %lld %lld], %d %d\n",L,R,k,bcnt,wcnt);
    if( wcnt == 0 && bcnt == 0 ) return;
    if( wcnt > 0 && bcnt == 0 ) return;
    if( wcnt == 0 && bcnt > 0 ){
        ans.push_back(ll_to_IP(L,k));
        return;
    }
    dfs(L, (L+R)/2, k+1);
    dfs((L+R)/2+1, R, k+1);
}

int main() {
    pow2[0] = 1;
    for(ll i=1;i<=500;i++) pow2[i] = pow2[i-1] * 2LL;

    scanf("%d",&N);
    vector<pair<pll,ll>> event;
    vector<pair<int,pll>> iplist;

    repp(i,N){
        scanf("%s",buf);
        string s = buf;
        pair<int,pll> res = IP_to_range(s);
        iplist.pb(res);
        if( res.Fi == 1 ){
            wlist.push_back(res.Se);
            event.push_back({{res.Se.Fi, 1}, 1});
            event.push_back({{res.Se.Se, 2}, 1});
        }
        if( res.Fi == -1 ){
            blist.push_back(res.Se);
            event.push_back({{res.Se.Fi, 1}, -1});
            event.push_back({{res.Se.Se, 2}, -1});
        }
        idx.push_back(res.Se.Fi); idx.push_back(res.Se.Se);
    }

    sort(all(idx)); idx.erase(unique(all(idx)), idx.end());

    /* check valid */
    sort(all(event));
    int wcnt = 0, bcnt = 0;
    for(auto e : event){
        int type = e.Fi.Se, color = e.Se;
        if( type == 1 ){
            if( color == 1 ) wcnt++;
            else bcnt++;
        }
        if( type == 2 ){
            if( color == 1 ) wcnt--;
            else bcnt--;
        }

        if( wcnt && bcnt ){
            printf("-1\n");
            return 0;
        }
    }

    for(auto e : iplist){
        int sign = e.Fi; ll L = e.Se.Fi, R = e.Se.Se;
    //    printf("!%d %lld %lld\n",sign,L,R);
        if( sign == 1 ){
            tW[get_idx(L)]++;
            tW[get_idx(R)+1]--;
        }
        else{
            tB[get_idx(L)]++;
            tB[get_idx(R)+1]--;
        }
    }
    WS[0] = tW[0]; BS[0] = tB[0];
    for(int i=1;i<=1000000;i++){
        WS[i] = WS[i-1] + tW[i];
        BS[i] = BS[i-1] + tB[i];
    }
    for(int i=1;i<=1000000;i++){
        WS[i] = WS[i-1] + WS[i];
        BS[i] = BS[i-1] + BS[i];
    }



    ll low = 0, high = (1LL<<32LL)-1;
    dfs(low,high,0);

    printf("%d\n",sz(ans));
    for(auto e : ans){
        printf("%s\n",e.c_str());
    }

}