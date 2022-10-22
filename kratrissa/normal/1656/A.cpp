#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],mx,mn,cx,cn;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        printf("%d %d\n",min_element(a+1,a+n+1)-a,max_element(a+1,a+n+1)-a);
    }
    return 0;
}