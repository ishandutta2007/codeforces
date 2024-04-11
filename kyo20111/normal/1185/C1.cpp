#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t[202020],sum;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    for(int i=1;i<=n;i++){
        if(sum + t[i] <= m){
            printf("0 ");
        }else{
            int l = 1,mn = 0, cnt = 0;
            while(sum - mn + t[i] > m){
                mn += t[l];
                cnt++;
                l++;
            }
            printf("%d ",cnt);
        }
        sum += t[i];
        sort(t+1,t+1+i,greater<int>());
    }
}