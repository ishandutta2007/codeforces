#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b,a,aa,arr[202020];
int main(){
    scanf("%d %d %d",&n,&b,&a);
    aa=a;
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    for(int i=1;i<=n;i++){
        if(arr[i] == 0){
            if(a) a--;
            else if(b) b--;
            else return !printf("%d",i-1);
        }
        else if(arr[i] == 1){
            if(b && a<aa) b--,a++;
            else if(a) a--;
            else if(b) b--;
            else return !printf("%d",i-1);
        }
    }

    printf("%d",n);
}