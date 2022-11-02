#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int aid[2001];
ll dr[2001];

vector<pair<int,ll> > g[2001];

struct e{
    int a;
    int b;
    ll w;
    bool operator<(const e&e2) const{
        return w<e2.w;
    }
};

vector<e> check;

void dfs(int x, int a){
    if (aid[x]==a) return;
    aid[x]=a;
    for (auto nx:g[x]){
        dfs(nx.first, a);
    }
}

int f=0;

const int N=4010;

int misp[N*2];
int mispi[N*2];

void setmin(int i, int x, int ii){
    for (i+=N;i;i/=2){
        if (misp[i]==0||misp[i]>x) {
            misp[i]=x;
            mispi[i]=ii;
        }
    }
}

int getmin(int a, int b){
    a+=N;
    b+=N;
    int mi=1e9;
    int mv=0;
    while(a<=b){
        if (a%2){
            if (misp[a]>0&&misp[a]<mi){
                mi=misp[a];
                mv=mispi[a];
            }
            a++;
        }
        if (!(b%2)){
            if (misp[b]>0&&misp[b]<mi){
                mi=misp[b];
                mv=mispi[b];
            }
            b--;
        }
        a/=2;
        b/=2;
    }
    return mv;
}

int ind[2001];

int j=0;

void dfs2(int x, ll d, int dd, int p){
    j++;
    ind[x]=j;
    setmin(j, dd, x);
    dr[x]=d;
    f++;
    for (auto nx:g[x]){
        if (nx.first!=p) {
            dfs2(nx.first, d+nx.second, dd+1, x);
            j++;
            setmin(j, dd, x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<e> es;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            int d;
            cin>>d;
            if (i!=ii){
                if (d==0){
                    cout<<"NO"<<endl;
                    return 0;
                }
                es.push_back(e{i, ii, d});
            }
            if (i==ii&&d>0) {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    sort(es.begin(), es.end());
    for (int i=0;i<n;i++){
        aid[i]=i;
    }
    for (e ed:es){
        if (aid[ed.a]==aid[ed.b]){
            check.push_back(ed);
        }
        else{
            g[ed.a].push_back(make_pair(ed.b, ed.w));
            g[ed.b].push_back(make_pair(ed.a, ed.w));
            dfs(ed.b, aid[ed.a]);
        }
    }
    dfs2(0, 0, 1, -1);
    if (f<n) {
        cout<<"NO"<<endl;
        return 0;
    }
    for (e ed:check){
        int ay=getmin(min(ind[ed.a], ind[ed.b]), max(ind[ed.a], ind[ed.b]));
        //cout<<"az "<<ed.a<<" "<<ed.b<<" "<<ay<<endl;
        ll d=dr[ed.a]+dr[ed.b]-2ll*dr[ay];
        if (d!=ed.w){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}