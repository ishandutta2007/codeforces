#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,j=n;i<=j;i++,j--){
        if(i==j){
                //cout<<m/2<<endl;
                for(int k=1;k<=m/2;k++){
                    printf("%d %d\n",i,k);
                    printf("%d %d\n",i,m-k+1);
                }
                if(m&1)printf("%d %d\n",i,m/2+1);
            }
        else{
        for(int k=1,l=m;k<=m&&l>=1;k++,l--){
            printf("%d %d\n",i,k);
            printf("%d %d\n",j,l);
        }
        }
    }
}