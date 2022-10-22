#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
char s[maxn];
char a[maxn];
char b[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",s);
        if(s[0]=='0' || s[n-1]=='0') {
            printf("NO\n");
            continue;
        }
        int c0=0,c1=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') c1++;
        }
        if(n%2!=0 || c1%2!=0) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        c1/=2;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                if(c1>0) {
                    a[i]='(';
                    b[i]='(';
                }
                else {
                    a[i]=')';
                    b[i]=')';
                }
                c1--;
            }
            else {
                if(c0==0) {
                    a[i]='(';
                    b[i]=')';
                }
                else {
                    a[i]=')';
                    b[i]='(';
                }
                c0^=1;
            }
        }
        a[n]=b[n]=0;
        printf("%s\n",a);
        printf("%s\n",b);
    }
    return 0;
}