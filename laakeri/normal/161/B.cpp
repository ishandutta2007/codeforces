#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int u[1010];
int c[1010];
int t[1010];
vector<int> v[1010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int, int> > ss;
    vector<pair<int, int> > is;
    for (int i=1;i<=n;i++){
        cin>>c[i]>>t[i];
        c[i]*=2;
        is.push_back({c[i], i});
        if (t[i]==1){
            ss.push_back({c[i], i});
        }
    }
    sort(is.begin(), is.end());
    sort(ss.begin(), ss.end());
    int i2=0;
    for (int i=ss.size()-1;i>=0;i--){
        if (u[ss[i].S]==0){
            v[i2].push_back(ss[i].S);
            u[ss[i].S]=1;
            if (i2<k-1) i2++;
        }
    }
    for (int i=0;i<(int)is.size();i++){
        if (u[is[i].S]==0){
            v[i2].push_back(is[i].S);
            u[is[i].S]=1;
            if (i2<k-1) i2++;
        }
    }
    ll vv=0;
    for (int i=0;i<k;i++){
        ll p=0;
        int hs=0;
        ll mp=2e9+10;
        for (int ii=0;ii<(int)v[i].size();ii++){
            p+=(ll)c[v[i][ii]];
            if (t[v[i][ii]]==1){
                hs=1;
            }
            mp=min(mp, (ll)c[v[i][ii]]);
        }
        vv+=p;
        if (hs) vv-=mp/2ll;
    }
    cout<<fixed<<setprecision(1)<<(double)vv/(double)2<<endl;
    for (int i=0;i<k;i++){
        cout<<v[i].size()<<" ";
        for (int a:v[i]){
            cout<<a<<" ";
        }
        cout<<'\n';
    }
}