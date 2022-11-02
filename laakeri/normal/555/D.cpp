#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

pair<ll, int> x[1020201];
int t[1020201];
int u[1020201];
int k[1010101];

int n;

vector<pair<ll, int> > cs;

pair<int, ll> getn(int i, ll xx){
    int mi=i;
    int ma=cs.size()-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (cs[m].F<=cs[i].F+xx){
            mi=m+1;
        }
        else{
            ma=m-1;
        }
    }
    if (ma>i){
        return {k[ma], cs[ma].F-cs[i].F};
    }
    else if(i<n-1){
        i=u[i];
        mi=i;
        ma=cs.size()-1;
        while (mi<=ma){
            int m=(mi+ma)/2;
            if (cs[m].F<=cs[i].F+xx){
                mi=m+1;
            }
            else{
                ma=m-1;
            }
        }
        if (ma>i){
            return {k[ma], cs[ma].F-cs[i].F};
        }
        else{
            return {k[i], 0};
        }
    }
    else{
        return {k[i], 0};
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x[i].F;
        x[i].S=i+1;
    }
    sort(x, x+n);
    for (int i=1;i<n;i++){
        t[x[i].S]=i;
        x[i].F-=x[0].F;
    }
    x[0].F=0;
    ll l=x[n-1].F*2ll;
    for (int i=0;i<n;i++){
        k[cs.size()]=i;
        cs.push_back({x[i].F, i});
    }
    for (int i=n-2;i>=1;i--){
        u[i]=cs.size();
        k[cs.size()]=i;
        cs.push_back({cs.back().F+(x[i+1].F-x[i].F), i});
    }
    for (int i=0;i<n;i++){
        k[cs.size()]=i;
        cs.push_back({l+x[i].F, i});
    }
    for (int i=n-2;i>=1;i--){
        k[cs.size()]=i;
        cs.push_back({cs.back().F+(x[i+1].F-x[i].F), i});
    }
    /*
    cout<<l<<endl;
    for (auto tt:cs){
        cout<<tt.F<<" "<<tt.S<<endl;
    }*/
    for (int qq=0;qq<m;qq++){
        int a;
        ll xx;
        cin>>a>>xx;
        if (n==1){
            cout<<"1\n";
            continue;
        }
        xx%=l;
        a=t[a];
        while (1){
            auto ne=getn(a, xx);
            if (ne.S==0){
                cout<<x[ne.F].S<<'\n';
                break;
            }
            auto ne2=getn(ne.F, xx-ne.S);
            if (ne2.S==0){
                cout<<x[ne2.F].S<<'\n';
                break;
            }
            if (ne2.F==a){
                xx%=(ne.S+ne2.S);
            }
            else{
                xx=xx-ne.S-ne2.S;
                a=ne2.F;
            }
        }
    }
}