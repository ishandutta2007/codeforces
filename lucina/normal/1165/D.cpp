#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define ll long long
int t,n,a[maxn],mi,ma;
ll x;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mi=1000005;ma=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            ma=max(ma,a[i]);
            mi=min(mi,a[i]);
        }
        sort(a,a+n);
        vector<ll> d;
        x=1ll*ma*mi;
        int y=sqrt(x);
        for(int i=y;i>=2;i--){
            if(x%i==0){
                if(x/i!=i)
                    d.push_back(x/i);
                d.push_back(i);
            }
        }
        sort(d.begin(),d.end());
        bool ch=true;
        ch&=(d.size()==n);
        for(int i=0;i<n;i++){
            ch&=(d[i]==a[i]);
        }
        printf("%lld\n",ch?x:-1ll);
    }

}