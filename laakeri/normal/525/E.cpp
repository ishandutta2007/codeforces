#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

unordered_map<ll, int> v1s[30];

int a[30];
ll fac[30];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fac[0]=1;
    for (ll i=1;i<20;i++){
        fac[i]=fac[i-1]*i;
    }
    int n,k;
    ll su;
    cin>>n>>k>>su;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int fp=n/2;
    int sp=n-n/2;
    for (int i=0;i<(1<<fp);i++){
        int has=__builtin_popcount(i);
        for (int ii=0;ii<(1<<has);ii++){
            int has2=__builtin_popcount(ii);
            if (has2<=k){
                int ok=1;
                int c=0;
                ll s=0;
                for (int j=0;j<fp;j++){
                    if ((1<<j)&i){
                        if ((1<<c)&ii){
                            if (a[j]>=20){
                                ok=0;
                                break;
                            }
                            else{
                                s+=fac[a[j]];
                            }
                        }
                        else{
                            s+=a[j];
                        }
                        c++;
                    }
                }
                if (ok) v1s[has2][s]++;
            }
        }
    }
    ll v=0;
    for (int i=0;i<(1<<sp);i++){
        int has=__builtin_popcount(i);
        for (int ii=0;ii<(1<<has);ii++){
            int has2=__builtin_popcount(ii);
            if (has2<=k){
                int ok=1;
                int c=0;
                ll s=0;
                for (int j=0;j<sp;j++){
                    if ((1<<j)&i){
                        if ((1<<c)&ii){
                            if (a[fp+j]>=20){
                                ok=0;
                                break;
                            }
                            else{
                                s+=fac[a[fp+j]];
                            }
                        }
                        else{
                            s+=a[fp+j];
                        }
                        c++;
                    }
                }
                if (ok){
                    for (int iii=0;iii+has2<=k;iii++){
                        v+=(ll)v1s[iii][su-s];
                    }
                }
            }
        }
    }
    cout<<v<<endl;
}