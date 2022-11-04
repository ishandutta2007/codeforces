#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<ll,int> p[202020];

bool f(){
    int fl=0,out=p[n].second;
    if((p[2].first - p[1].first) * 2 == p[3].first - p[1].first){
        ll g = p[2].first - p[1].first;
        for(int i=2;i<=n;i++){
            if(p[1].first + g * (i-1-fl) != p[i].first) fl++,out=p[i].second;
        }
        if(fl >= 2) return false;
        printf("%d",out);
        return true;
    }
    if((p[2].first - p[1].first) * 2 == p[4].first - p[1].first){
        ll g = p[2].first - p[1].first;
        fl = 1;
        out = p[3].second;
        for(int i=4;i<=n;i++){
            if(p[1].first + g * (i-1-fl) != p[i].first) return false;
        }
        printf("%d",out);
        return true;
    }
    if((p[3].first - p[1].first) * 2 == p[4].first - p[1].first){
        ll g = p[3].first - p[1].first;
        fl = 1;
        out = p[2].second;
        for(int i=3;i<=n;i++){
            if(p[1].first + g * (i-1-fl) != p[i].first) return false;
        }
        printf("%d",out);
        return true;
    }
    if((p[3].first - p[2].first) * 2 == p[4].first - p[3].first){
        ll g = p[3].first - p[2].first;
        fl = 1;
        out = p[1].second;
        for(int i=3;i<=n;i++){
            if(p[2].first + g * (i-1-fl) != p[i].first) return false;
        }
        printf("%d",out);
        return true;
    }

    return false;
}
int main(){
    scanf("%d",&n);
    if(n <= 3) return !printf("1");
    for(int i=1;i<=n;i++) scanf("%lld",&p[i].first);
    for(int i=1;i<=n;i++) p[i].second = i;

    sort(p+1,p+1+n);
    if(f()) return 0;
    sort(p+1,p+1+n,greater<pair<ll,int>>());
    if(f()) return 0;
    printf("-1");
}