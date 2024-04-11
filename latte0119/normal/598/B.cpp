#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
typedef vector<int>vint;
typedef pair<int,int>pint;

string S;
int M;

signed main(){
    cin>>S>>M;
    while(M--){
        int l,r,k;cin>>l>>r>>k;
        l--;
        k%=(r-l);
        rotate(S.begin()+l,S.begin()+r-k,S.begin()+r);
    }
    cout<<S<<endl;
    return 0;
}