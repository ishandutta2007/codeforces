#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    string a,b;
    cin>>a>>b;


    vector<string>latte;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            latte.pb(a.substr(0,i)+b.substr(0,j));
        }
    }
    cout<<*min_element(all(latte))<<endl;
    return 0;
}