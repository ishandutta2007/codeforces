#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];
bool used[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1 ;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ct=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        ct++;
        for(int j=i;j<=n;j++){
            if(a[j]%a[i]==0)used[j] = true;
        }

    }
    printf("%d\n",ct);
}
/*
    Good Luck
        -Lucina
*/