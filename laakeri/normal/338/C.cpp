#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> ps;

int pds(ll x){
    int v=0;
    for (ll p:ps){
        while (x%p==0){
            x/=p;
            v++;
        }
        if (p*p>x) break;
    }
    if (x>1) v++;
    return v;
}

ll a[10];

int dp[1<<8];

void cbit(int bm, int n){
    for (int i=0;i<n;i++)
        if ((1<<i)&bm) cout<<1;
        else cout<<0;
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for (int i=2;i<=1000000;i++){
        int f=0;
        for (int p:ps){
            if (i%p==0){
                f=1;
                break;
            }
            if (p*p>i) break;
        }
        if (!f){
            ps.push_back(i);
        }
    }
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int v=1e6;
    ll lolma=6e11;
    for (int i=1;i<(1<<n);i++){
        int mi=1e6;
        int tn=0;
        for (int ii=0;ii<n;ii++){
            if ((1<<ii)&i){
                tn=ii;
            }
        }
        if (tn==0) mi=pds(a[tn])+1;
        if (mi==2) mi=1;
        for (int ii=0;ii<(1<<tn);ii++){
            int ok=1;
            ll d=1;
            int ck=0;
            if ((ii&(1<<(tn-1)))==0) continue;
            for (int iii=0;iii<tn;iii++){
                if ((!((1<<iii)&i))&&(1<<iii)&ii){
                    if ((double)d*(double)a[iii]>lolma){
                        d=lolma;
                    }
                    else{
                        d*=a[iii];
                    }
                }
                if ((!((1<<iii)&ii))&&(1<<iii)&i){
                    ok=0;
                    break;
                }
            }
            if (ok){
                if (a[tn]%d==0){
                    int lol=pds(a[tn]/d);
                    if (lol==1&&d==1) {
                        lol=0;
                    }
                    mi=min(mi, dp[ii]+lol+1);
                }
            }
        }
        dp[i]=mi;
        if (tn==n-1){
            if (i==(1<<(n-1))){
                v=min(v, mi);
            }
            else{
                v=min(v, mi+1);
            }
        }
    }
    cout<<v<<endl;
}