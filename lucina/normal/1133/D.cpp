#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],b[maxn],ans;
unordered_map<long double,int> x;
int main(){
    x.reserve(131072);
    x.max_load_factor(0.25);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    long double g;
    int fuck=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            if(b[i]==0){
                fuck++;
                }
        }
        else{
        g=((long double)(-b[i]))/((long double)(a[i]));
        ans=max(ans,++x[g]);
        }

    }
    printf("%d\n",ans+fuck);
}