#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> d[100001];
set<ll> ns;
ll t[100001];
vector<ll> lol;
ll c=0;

ll f (ll x,ll y){//x korvataan y:ll
    ll v=0;
    for (ll l:d[x]){
        v-=abs(l);
        v+=abs(x+l-y);
    }
    return v;
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>t[i];
        ns.insert(t[i]);
    }
    for (int i=1;i<m-1;i++){
        if (t[i-1]!=t[i]) d[t[i]].push_back(t[i-1]-t[i]);
        if (t[i+1]!=t[i]) d[t[i]].push_back(t[i+1]-t[i]);
    }
    if (t[0]!=t[1]) d[t[0]].push_back(t[1]-t[0]);
    if (t[m-1]!=t[m-2]) d[t[m-1]].push_back(t[m-2]-t[m-1]);
    for (int i=0;i<m-1;i++){
        c+=abs(t[i]-t[i+1]);
    }
    for (ll a:ns){
        lol.push_back(a);
    }
    ll br=0;
    for (ll a:lol){
        /*
        for (ll b:lol){
            cout <<a<<" "<<f(a,b)<<endl;
        }
        */
        int mi=0;
        int ma=lol.size()-1;
        while (mi<ma){
            int mid=(mi+ma)/2;
            ll lol1=f(a,lol[mid]);
            ll lol2=f(a,lol[mid+1]);
            if (lol1<lol2){
                ma=mid;
            }
            else{
                mi=mid+1;
            }
            br=min(br,min(lol1,lol2));
        }
        //cout <<a<<" "<<f(a,lol[mi])<<" "<<f(a,lol[ma])<<endl;
    }
    //cout <<c<<endl;
    cout <<c+br<<endl;
}