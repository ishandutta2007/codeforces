#include <bits/stdc++.h>
using namespace std;
int n,arr[222][11],cnt[11],chk[11];
int f2(int a,int b,int c){
    if(c == -1) return 0;

    int sc;
    if(a*2 > b) sc = 500;
    else if(a*4 > b) sc = 1000;
    else if(a*8 > b) sc = 1500;
    else if(a*16 > b) sc = 2000;
    else if(a*32 > b) sc = 2500;
    else sc = 3000;

    return sc - sc * c / 250;
}
bool f(int a){
    int A=0,B=0;
    for(int i=1;i<=5;i++) A += f2(cnt[i]+chk[i]*a,n+a,arr[1][i]),B += f2(cnt[i]+chk[i]*a,n+a,arr[2][i]);
    if(A > B) return true;
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%d",&arr[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) if(arr[i][j] != -1) cnt[j]++;
    for(int i=1;i<=5;i++) if(arr[1][i] != -1 && arr[1][i] > arr[2][i] && arr[2][i] != -1) chk[i]=1;
    for(int i=0;i<=n*32;i++) if(f(i)) return !printf("%d",i);
    printf("-1");
}