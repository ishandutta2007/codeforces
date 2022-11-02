#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf=1e18;

ll b,c;

ll cost(ll from, ll to){
    ll k=(to-from);
    return (k/5)*b+(k%5)*c;
}

vector<ll> h[5];
vector<ll> test[5];
int i2[5];

ll t[202020];

deque<ll> e[5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k>>b>>c;
    if (c*5<b) b=c*5;
    for (int i=0;i<n;i++){
        cin>>t[i];
        t[i]+=(ll)1e9+2;
        h[t[i]%5].push_back(t[i]);
        for (int j=0;j<5;j++){
            test[(t[i]+j)%5].push_back(t[i]+j);
        }
    }
    for (int i=0;i<5;i++){
        sort(h[i].begin(), h[i].end());
        sort(test[i].begin(), test[i].end());
    }
    ll v=inf;
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            e[j].clear();
            i2[j]=0;
        }
        ll nn=0;
        ll nc=0;
        ll ef=0;
        for (ll f:test[i]){
            nc+=nn*((f-ef)/5ll)*b;
            ef=f;

            //cout<<f<<" "<<nn<<" "<<nc<<endl;

            for (int j=0;j<5;j++){
                while (i2[j]<(int)h[j].size()&&h[j][i2[j]]<=f){
                    int o=0;
                    if (nn<k){
                        e[j].push_back(h[j][i2[j]]);
                        nc+=cost(h[j][i2[j]], f);
                        nn++;
                        o=1;
                        i2[j]++;
                    }
                    else{
                        ll ma=0;
                        for (int jj=0;jj<5;jj++){
                            if ((int)e[jj].size()>0){
                                ma=max(ma, cost(e[jj].front(), f));
                            }
                        }
                        if (ma>cost(h[j][i2[j]], f)){
                            for (int jj=0;jj<5;jj++){
                                if ((int)e[jj].size()>0){
                                    if (cost(e[jj].front(), f)==ma){
                                        //cout<<e[jj].front()<<" "<<f<<" "<<ma<<endl;
                                        e[jj].pop_front();
                                        break;
                                    }
                                }
                            }
                            nc+=cost(h[j][i2[j]], f)-ma;
                            o=1;
                            e[j].push_back(h[j][i2[j]]);
                            i2[j]++;
                        }
                    }
                    if (!o) break;
                }
            }
            //cout<<f<<" "<<nn<<" "<<nc<<endl;
            if (nn==k){
                v=min(v, nc);
            }
        }
    }
    cout<<v<<endl;
}