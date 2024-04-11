#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, q, chk[1000001], bu[1000001], sq = 1000;
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        chk[a]++;
        bu[a/sq]++;
    }
 
    for(int i=1;i<=q;i++){
        int a; scanf("%d",&a);
        if(a > 0){
            chk[a]++;
            bu[a/sq]++;
        }else{
            a = -a;
            for(int j=0;j<=n/sq;j++){
                if(bu[j] >= a){
                    for(int k=0;k<sq;k++){
                        if(chk[j*sq+k] >= a){
                            chk[j*sq+k]--;
                            break;
                        }
                        a -= chk[j*sq+k];
                    }
                    bu[j]--;
                    break;
                }
                a -= bu[j];
            }
        }
    }
 
    for(int i=1;i<=n;i++) if(chk[i]) return !printf("%d",i);
    printf("0");
}