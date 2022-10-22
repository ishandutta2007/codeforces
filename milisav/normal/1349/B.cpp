#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 200000
using namespace std;
int n,k;
int t;
int pf=0;
int a[maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
        scanf("%d %d",&n,&k);
        bool ex=false;
        bool t1=false;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if(a[i]==k) t1=true;
        }
        pf=0;
        for(int i=1;i<=n;i++) {
            if(a[i]>=k && (pf>=0 && i!=1)) ex=true;
            if(a[i]>=k) pf=max(1,pf+1);
            else pf=max(-1,pf-1);
        }
        reverse(a+1,a+n+1);
        pf=0;
        for(int i=1;i<=n;i++) {
            if(a[i]>=k && (pf>=0 && i!=1)) ex=true;
            if(a[i]>=k) pf=max(1,pf+1);
            else pf=max(-1,pf-1);
        }
        if((t1 && ex) || (n==1 && a[1]==k)) printf("yes\n");
        else printf("no\n");
	}
	return 0;
}