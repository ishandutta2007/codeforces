#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int dv[505050];

int has[505050];

int a[505050];
int h[505050];

void goc(int x, vector<pair<int, int> >&ds, int i, vector<pair<int, int> >&r, int c){
    if (i==ds.size()){
        if (x>1){
            r.push_back({x, c});
        }
    }
    else{
        goc(x, ds, i+1, r, c);
        goc(x*ds[i].F, ds, i+1, r, c+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=2;i<=500000;i++){
        if (dv[i]==0){
            for (int ii=i;ii<=500000;ii+=i){
                dv[ii]=i;
            }
        }
    }
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int v=0;
    int hh=0;
    for (int i=0;i<q;i++){
        int t;
        cin>>t;
        t--;
        vector<pair<int, int> > ds;
        vector<pair<int, int> > r;
        int x=a[t];
        while (x>1){
            if ((int)ds.size()>0&&ds.back().F==dv[x]) ds.back().S++;
            else ds.push_back({dv[x], 1});
            x/=dv[x];
        }
        goc(1, ds, 0, r, 0);
        int co=0;
        for (auto s:r){
            if (s.S%2==1){
                co+=has[s.F];
                if (h[t]==1) co--;
            }
            else{
                co-=has[s.F];
                if (h[t]==1) co++;
            }
        }
        if (h[t]==0){
            h[t]=1;
            v+=co;
            for (auto s:r){
                has[s.F]++;
                //cout<<s.F<<"+"<<endl;
            }
            hh++;
        }
        else{
            h[t]=0;
            v-=co;
            for (auto s:r){
                has[s.F]--;
            }
            hh--;
        }
        cout<<((ll)hh*((ll)hh-1ll)/2ll)-(ll)v<<'\n';
    }
}