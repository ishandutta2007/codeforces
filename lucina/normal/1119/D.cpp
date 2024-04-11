#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,q;
long long l,r,s,a[maxn],qs[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    vector<long long> b;
    for(int i=1;i<=n;i++){
        int pt=i;
        while(pt<=n&&a[pt]==a[i])
            pt++;
        pt--;
        b.push_back(a[i]);
        i=pt;
    }
    long long ba=b.size();
    vector<long long> dif;
    for(int i=1;i<b.size();i++){
        dif.push_back(b[i]-b[i-1]-1);
    }
    dif.push_back(2e18+5);
    sort(dif.begin(),dif.end());
    for(int i=0;i<dif.size();i++){
        qs[i]=i>0?qs[i-1]:0;
        qs[i]+=dif[i];
    }
    scanf("%d",&q);
    n=dif.size();
    long long d,ans,sum=0,w;
    while(q--){
        scanf("%lld%lld",&l,&r);
        d=(r-l);
        ans=ba;
        auto it=upper_bound(dif.begin(),dif.end(),d)-dif.begin();
         w=it-1;
        ans+=(qs[w]+(d)*(n-w-1));
        printf("%lld ",ans);
    }
}
/*
    Lucina
*/