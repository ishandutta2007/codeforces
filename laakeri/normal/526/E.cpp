#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll a[1010101];
ll dp[1010101];
ll o[1010101];

ll st[1010101];
ll sum(int a, int b){
    ll s=st[b];
    if (a) s-=st[a-1];
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=0;i<n;i++){
        cin>>a[i];
        st[i]=a[i];
        if (i) st[i]+=st[i-1];
    }
    for (int qq=0;qq<q;qq++){
        ll b;
        cin>>b;
        int i2=n-1;
        int f=0;
        for (int i=i2;i>=0;i--){
            if (sum(i, i2)>b) break;
            f=i;
            dp[i]=1;
            o[i]=b-sum(i, i2);
        }
        for (int i=f-1;i>=0;i--){
            while (sum(i, i2)>b){
                i2--;
            }
            dp[i]=dp[i2+1]+1;
            o[i]=o[i2+1];
        }
        int v=dp[0];
        for (int i=1;i<n;i++){
            if (dp[i]==v-1&&o[i]>=sum(0, i-1)){
                v=v-1;
                break;
            }
        }
        cout<<v<<endl;
    }
}