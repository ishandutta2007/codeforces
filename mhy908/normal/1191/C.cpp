#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, arr[100010], k;
int m, ans, pv=1;
int main()
{
    scanf("%lld %d %lld", &n, &m, &k);
    for(int i=1; i<=m; i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=1; i<=m;){
        LL fr=i-1;
        LL num=arr[i]-fr;
        if(num%k)num=num/k*k;
        else num-=k;
        while(pv<=m){
            if(num+k>=arr[pv]-fr){
                pv++;
            }
            else break;
        }
        i=pv;
        ans++;
    }
    printf("%d", ans);
}