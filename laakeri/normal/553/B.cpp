#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll cnt[100];

void go(int n, int p, ll k){
    if (n==0) return;
    int f=0;
    ll s=0;
    for (int i=1;i<=2;i++){
        s+=cnt[n-i];
        //cout<<n<<" "<<k<<" "<<i<<" "<<s<<endl;
        if (s>=k){
            f=i;
            s-=cnt[n-i];
            break;
        }
    }
    k-=s;
    for (int i=f;i>=1;i--){
        cout<<i+p<<" ";
    }
    go(n-f, p+f, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cnt[0]=1;
    cnt[1]=1;
    for (int i=2;i<60;i++){
        cnt[i]=cnt[i-1]+cnt[i-2];
    }
    int n;
    ll k;
    cin>>n>>k;
    go(n, 0, k);
}