#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int q,n,pt,a[maxn];
long long p2[maxn];
int main(){
    p2[0]=1;
    for(int i=1;i<=30;i++){
        p2[i]=p2[i-1]*2;
    }
    scanf("%d",&q);
    for(int kk=1;kk<=q;kk++){
        scanf("%d",&n);
        if(n==2){
            printf("3\n");
            continue;
        }
        pt=0;
        while(p2[pt]<=n){
            pt++;
        }
    //    printf("%lld\n",p2[pt]);
        if(n!=p2[pt]-1){
            printf("%lld\n",p2[pt]-1);
            continue;
        }
        int x=sqrt(n);
        bool ch;
        ch=true;
        for(int i=2;i<=x;i++){
            if((n)%i==0){
                printf("%d\n",(n)/i);
                ch=false;
                break;
            }
        }
        if(ch){
            printf("1\n");
        }
    }


}