#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[4],d;
long long ma=3e9;

int main(){
    for(int i=1;i<=3;i++)
    scanf("%d",&a[i]);
    scanf("%d",&d);
    sort(a+1,a+4);
    ma=min(ma,0LL+max(0,d-a[2]+a[1])+max(0,d-a[3]+a[2]));
    printf("%lld\n",ma);
}
/*
    Good Luck
         -Lucina
*/