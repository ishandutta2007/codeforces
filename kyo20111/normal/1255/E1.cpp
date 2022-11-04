#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[100100], cnt, c;
ll ans = 1e18;
vector<int> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    for(int i=1;i<=n;i++) cnt += a[i];

    if(cnt <= 1) return !printf("-1");


    for(int i=1;i<=n;i++){
        if(a[i]){
            v.push_back(i);
        }
    }

    for(int i=2;i<=cnt;i++){
        if(cnt % i == 0){
            ll re = 0;
            for(int j=0;j<v.size();j++){
                re += abs(v[j] - v[i*(j/i) + (i+1)/2 -1]);
                //printf("%d %d\n",j,i*(j/i) + (i+1)/2);
            }
            //printf("%d %lld\n",i,re);
            ans = min(ans, re);
        }
    }

    printf("%lld",ans);
}