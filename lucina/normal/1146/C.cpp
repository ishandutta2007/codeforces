#include<bits/stdc++.h>
using namespace std;
int t,n,ma,x;

//another sol
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ma=0;
        for(int i=0;i<9;i++){
            vector<int> f1,f2;
            for(int j=1;j<=n;j++){
                if(1&(j>>i)){
                    f1.push_back(j);
                }
                else
                    f2.push_back(j);
            }
            if(f1.size()>=1&&f2.size()>=1){
            printf("%d %d ",f1.size(),f2.size());
            for(int j:f1)printf("%d ",j);
            for(int j:f2)printf("%d ",j);
            printf("\n");fflush(stdout);
            scanf("%d",&x);
            ma=max(ma,x);
            }
        }
        printf("-1 %d\n",ma);
        fflush(stdout);
    }

}
/*
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d %d 1 ",1,n-1);
        for(int i=2;i<=n;i++)
            printf("%d ",i);
            printf("\n");
            fflush(stdout);
        scanf("%d",&ma);
        l=2,r=n;
        while(l<=r){
            mid=(l+r)>>1;
            printf("%d %d 1 ",1,mid-l+1);
            for(int i=l;i<=mid;i++)
                printf("%d ",i);
            printf("\n");
            fflush(stdout);
            scanf("%d",&x);
            if(x<ma){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d %d %d ",1,n-1,l);
        for(int i=1;i<=n;i++){
            if(i!=l)
                printf("%d ",i);
        }
        printf("\n");fflush(stdout);
        scanf("%d",&x);
        printf("-1 %d\n",x);
        fflush(stdout);
    }


}
*/