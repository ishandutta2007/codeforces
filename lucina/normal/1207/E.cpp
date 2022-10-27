#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int x,ans;

int main(){
   /// int a=5;
    printf("? ");
  //  vector<int> res;
    for(int i=1;i<=100;i++){
    printf("%d ",i);
    //    res.push_back(i);
    }
   // x=res[rand()%100]^a;
    printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    for(int i=7;i<=13;i++){
        if(x&(1<<i)){
            ans+=(1<<i);
        }
    }
    printf("? ");
   /// res.clear();
    for(int i=1;i<=100;i++){
        printf("%d ",i<<7);
   ///     res.push_back(i<<7);
    }
  ///  x=res[rand()%100]^a;
    printf("\n");
    fflush(stdout);
    scanf("%d",&x);
    for(int i=0;i<=6;i++){
        if(x&(1<<i))
            ans+=(1<<i);
    }
    printf("! %d\n",ans);
    fflush(stdout);
}
/*
    Good Luck
        -Lucina
*/