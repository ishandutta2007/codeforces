#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define ll long long
int n,k,a[maxn];
ll x;
int main(){
    scanf("%d%d",&n,&k);
    ll sum=(1ll*(k)*(k+1))/2;
    if(sum>n)return printf("NO"),0;
    x=n-sum;
    int y=x/k;
    for(int i=1;i<=k;i++){
        a[i]=i+(y);
    }
    x%=k;
    bool g=true;
    for(int i=k;i>=1&&x>0&&g;i--){
        while(g&&x&&(i==1||a[i]<a[i-1]*2)){
            for(int j=i;j<=k&&x&&g;j++){
                while(g&&x&&(j==1||a[j]<a[j-1]*2)){
                if(a[j]+1==a[j+1]){
                    g=false;
                    break;
                }
                a[j]++;
                x--;
                }
            }
        }
    }

    if(x)return printf("NO"),0;
    for(int i=1;i<k;i++){
        if(a[i]<a[i+1]&&a[i]*2>=a[i+1]);
        else{
            return printf("NO"),0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=k;i++)
        printf("%d ",a[i]);
}