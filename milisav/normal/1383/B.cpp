#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int c[30];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int j=0;j<30;j++) {
            c[j]=0;
            for(int i=0;i<n;i++) if(a[i]&(1<<j)) c[j]++;
        }
        int p=0;
        for(int j=29;j>=0;j--) {
            if(c[j]%4==1) {
                p=1;
                break;
            }
            else {
                if(c[j]%4==3) {
                    if((n-c[j])%2==0) p=-1;
                    else p=1;
                    break;
                }
            }
        }
        if(p==1) printf("WIN\n");
        if(p==0) printf("DRAW\n");
        if(p==-1) printf("LOSE\n");
    }
	return 0;
}