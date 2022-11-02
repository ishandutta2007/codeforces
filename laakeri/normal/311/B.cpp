#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct line{
    ll k;
    ll b;
    ll v(ll x){
        return k*x+b;
    }
};

int isbad(line l1, line l2, line l3){
    if ((l2.b-l1.b)/(l1.k-l2.k)>=(l3.b-l1.b)/(l1.k-l3.k)) return 1;
    return 0;
}

ll dd[100001];
ll st[100001];
ll dp[101][100001];

int main(){
    ll n,m,p;
    cin>>n>>m>>p;
    for (int i=2;i<=n;i++){
        cin>>dd[i];
        dd[i]+=dd[i-1];
    }
    vector<ll> cs;
    for (int i=0;i<m;i++){
        ll h,t;
        cin>>h>>t;
        t-=dd[h];
        cs.push_back(t);
    }
    sort(cs.begin(), cs.end());
    for (int i=0;i<m;i++){
        st[i]+=cs[i];
        st[i+1]+=st[i];
    }
    vector<line> ls;
    ls.push_back(line{1, 0});
    for (ll i=0;i<p;i++){
        int bl=0;
        for (ll ii=0;ii<m;ii++){
            while (bl<ls.size()-1&&ls[bl].v(cs[ii])>=ls[bl+1].v(cs[ii])){
                bl++;
            }
            dp[i][ii]=ii*cs[ii]-st[ii]+ls[bl].v(cs[ii]);
        }
        ls.clear();
        for (ll ii=0;ii<m;ii++){
            line nl{-ii, dp[i][ii]+st[ii]};
            while (ls.size()>=2&&isbad(ls[ls.size()-2], ls.back(), nl)){
                ls.pop_back();
            }
            ls.push_back(nl);
        }
    }
    cout<<dp[p-1][m-1]<<endl;
}