#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x,y;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&x,&y);
        if((x<=3 && y>3) || (x==1 && y>1)) printf("NO\n");
        else printf("YES\n");
    }
}