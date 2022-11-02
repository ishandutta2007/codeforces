#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[303030];
int l[303030];
int r[303030];
int s[303030];
const int inf=1e9+10;
vector<int> ids[1010101];
int qr(int le, int ri, int m){
    return upper_bound(ids[m].begin(), ids[m].end(), ri)-lower_bound(ids[m].begin(), ids[m].end(), le);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int, int> > lol;
    lol.push_back({inf, -1});
    for (int i=0;i<n;i++){
        while (lol.size()>0&&lol.back().F<a[i]){
            lol.pop_back();
        }
        l[i]=lol.back().S+1;
        lol.push_back({a[i], i});
    }
    lol.clear();
    lol.push_back({inf, n});
    for (int i=n-1;i>=0;i--){
        while (lol.size()>0&&lol.back().F<=a[i]){
            lol.pop_back();
        }
        r[i]=lol.back().S-1;
        lol.push_back({a[i], i});
        //cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
    }
    ids[0].push_back(-1);
    for (int i=0;i<n;i++){
        s[i]=a[i];
        if (i) s[i]+=s[i-1];
        s[i]%=k;
        ids[s[i]].push_back(i);
    }
    ll v=0;
    for (int i=0;i<n;i++){
        if (i-l[i]<r[i]-i){
            for (int ii=i;ii>=l[i];ii--){
                int ss=0;
                if (ii) ss=s[ii-1];
                v+=(ll)qr(i, r[i], (ss+a[i])%k);
            }
        }
        else{
            for (int ii=i;ii<=r[i];ii++){
                v+=(ll)qr(l[i]-1, i-1, (s[ii]-(a[i])%k+k)%k);
            }
        }
    }
    cout<<v-(ll)n<<endl;
}