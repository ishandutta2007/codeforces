#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];
void ss(int x,int s){
    if(x==n+1){
        if(s%360)
            return;
        else{
            printf("YES");
            exit(0);
        }
    }
    s+=(a[x]);
    ss(x+1,s);
    s-=(2*a[x]);
    ss(x+1,s);

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ss(1,0);
    printf("NO");


}