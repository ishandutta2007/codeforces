#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    scanf("%d",&n);
    for(int i=9;i>=1;i--) if(n%i == 0){
        printf("%d\n",n/i);
        for(int j=1;j<=n/i;j++) printf("%d ",i);
        return 0;
    }
}