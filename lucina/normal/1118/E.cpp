#include<bits/stdc++.h>
using namespace std;
long long n,k,ct;

int main(){
    scanf("%lld%lld",&n,&k);
    if(k*k-k<n){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            printf("%d %d\n",i,j);
            ct++;
            if(ct==n)
                return 0;
            printf("%d %d\n",j,i);
            ct++;
            if(ct==n)
            return 0;
        }
    }

}