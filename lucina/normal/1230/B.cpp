#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int a[maxn];
 
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
    }
    if(n == 1){
        return !printf("%d\n",k > 0?0:/*n*/a[1]);
    }
    for(int i=1;i<=n;i++){
        if(i == 1){
            if(a[i] > 1 && k > 0){
                    --k;
                    a[i] = 1;
            }
        }
        else{
            if(a[i] > 0 && k> 0){
                --k;
                a[i]  = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d",a[i]);
}
/*
    Good Luck
        -Lucina
*/