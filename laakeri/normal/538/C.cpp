#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mh[202020];
ll d[202020];
ll h[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>m>>n;
    for (int i=0;i<n;i++){
        cin>>d[i]>>h[i];
    }
    mh[0]=h[0];
    for (int i=1;i<n;i++){
        if (abs(h[i]-h[i-1])>abs(d[i]-d[i-1])){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    ll ma=max(h[0]+d[0]-1, h[n-1]+(m-d[n-1]));
    for (int i=0;i<n-1;i++){
        for (ll ii=0;;ii++){
            if (h[i]+ii<h[i+1]||h[i]+ii-(d[i+1]-d[i]-ii)<=h[i+1]){
                ma=max(ma, h[i]+ii);
            }
            else{
                break;
            }
        }
    }
    cout<<ma<<endl;
}