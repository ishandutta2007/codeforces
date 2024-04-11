#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(a[i]!=0 && (i==0 || a[i]>a[i-1])) cnt++;
    }
    printf("%d\n",cnt);
}