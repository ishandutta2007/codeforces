#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n;
char a[maxn];
char b[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",a);
        int m=0;
        for(int i=0;i<n;i++) {
            if(a[i]=='b') b[m++]='b';
        }
        for(int i=0;i<n;i++) {
            if(a[i]!='b') b[m++]=a[i];
        }
        printf("%s\n",b);
        for(int i=0;i<n;i++) b[i]=0;
    }
    return 0;
}