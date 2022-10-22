#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
long long A,B,tot_dif;
int a[maxn];
int b[maxn];
int ca[maxn];
long long dif[maxn];
int n,m,t;
int main() {
    scanf("%d",&t);
    while(t--) {
        A=B=tot_dif=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            scanf("%d %d",&a[i],&b[i]);
            if(a[i]<m) {
                B+=(b[i]-(m-a[i]));
                ca[i]=a[i];
                if(b[i]<m) dif[i]=(a[i]-(m-b[i]));
                else dif[i]=a[i];
            }
            else {
                A+=(a[i]-m);
                B+=b[i];
                ca[i]=m;
                if(b[i]<m) dif[i]=(m-(m-b[i]));
                else dif[i]=m;
            }
            tot_dif+=dif[i];
        }
        long long nec_dif=0;
        if(A>=B) printf("%lld\n",A-B);
        else {
            if(A+tot_dif<=B-tot_dif) {
                nec_dif=tot_dif;
                printf("%lld\n",B-A-2*tot_dif);
            }
            else {
                nec_dif=(B-A)/2;
                printf("%lld\n",(A+B)%2);
            }
        }
        for(int i=0;i<n;i++) {
            ca[i]-=min(nec_dif,dif[i]);
            printf("%d %d\n",ca[i],m-ca[i]);
            nec_dif-=min(nec_dif,dif[i]);
        }
    }
    return 0;
}