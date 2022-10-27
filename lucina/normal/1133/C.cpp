#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],s,ct,ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    s=a[1];
    int pt1=1,pt2=1;
    while(true){
        if(pt1>pt2)
        pt2=pt1;
        while(a[pt2]-a[pt1]<=5&&pt2<=n){
            pt2++;
        }
        pt2--;
        ans=max(ans,pt2-pt1+1);
        pt1++;
        if(pt2>=n){
            break;
        }
    }
    printf("%d\n",ans);

}