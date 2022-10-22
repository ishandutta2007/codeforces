#include<bits/stdc++.h>
using namespace std;
int n;
int a[50000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int t=0;
    for(int i=0;i<n;i++) {
        if(a[i]%2==0) printf("%d ",a[i]/2);
        else {
            if(a[i]>0) printf("%d ",a[i]/2+t);
            else printf("%d ",a[i]/2-(1^t));
            t^=1;
        }
    }
    return 0;
}