#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll as[100001];

map<ll, int> ind;

const int N=600000;

int sp[2*N];
int spi[2*N];

void setm(ll i, int v, int ii){
    for (i=ind[i]+N;i;i/=2) {
        if (v>sp[i]){
            sp[i]=v;
            spi[i]=ii;
        }
    }
}

pair<int, int> getm(ll a, ll b){
    a=N+ind[a];
    b=N+ind[b];
    int v=0;
    int i=-1;
    while (a<=b){
        if (a%2) {
            if (sp[a]>v){
                v=sp[a];
                i=spi[a];
            }
            a++;
        }
        if (!(b%2)) {
            if (sp[b]>v){
                v=sp[b];
                i=spi[b];
            }
            b--;
        }
        a/=2;
        b/=2;
    }
    return make_pair(v, i);
}

int mf[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll d;
    cin>>n>>d;
    set<ll> vs;
    vs.insert(-1e17);
    vs.insert(1e17);
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        as[i]=a;
        vs.insert(a);
        vs.insert(a-d);
        vs.insert(a+d);
    }
    int id=1;
    for (ll v:vs){
        ind[v]=id;
        id++;
    }
    int mv=0;
    int mvi=0;
    for (int i=0;i<n;i++){
        auto m1=getm(-1e17, as[i]-d);
        auto m2=getm(as[i]+d, 1e17);
        pair<int, int> m;
        if (m1.F>m2.F){
            m=m1;
        }
        else{
            m=m2;
        }
        m.F++;
        if (m.F>mv){
            mv=m.F;
            mvi=i;
        }
        mf[i]=m.S;
        setm(as[i], m.F, i);
    }
    cout<<mv<<endl;
    vector<ll> v;
    while (mvi>=0){
        v.push_back(mvi);
        mvi=mf[mvi];
    }
    for (int i=mv-1;i>=0;i--){
        cout<<v[i]+1<<" ";
    }
}