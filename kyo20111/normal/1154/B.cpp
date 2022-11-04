#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[111];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    for(int i=0;i<=100;i++){
        int f=arr[1],fl=0;
        for(int j=2;j<=n;j++){
            if(arr[j]-i != f && arr[j]+i != f && arr[j] != f){
                fl=1;
                break;
            }
        }
        if(!fl) return !printf("%d",i);

        f=arr[1]+i,fl=0;
        for(int j=2;j<=n;j++){
            if(arr[j]-i != f && arr[j]+i != f && arr[j] != f){
                fl=1;
                break;
            }
        }
        if(!fl) return !printf("%d",i);

        f=arr[1]-i,fl=0;
        for(int j=2;j<=n;j++){
            if(arr[j]-i != f && arr[j]+i != f && arr[j] != f){
                fl=1;
                break;
            }
        }
        if(!fl) return !printf("%d",i);
    }
    printf("-1");
}