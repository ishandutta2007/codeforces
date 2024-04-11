#include<bits/stdc++.h>
using namespace std;
int T,n,k;
///Alice first Bob second
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        if(k%3){
            printf((n%3)?"Alice\n":"Bob\n");
        }
        else{
            n%=(k+1);
            printf((n==k||(n%3))?"Alice\n":"Bob\n");
        }
    }
    ///ok little tricky good that I didn't participate
}