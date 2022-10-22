    #include<bits/stdc++.h>
    using namespace std;
    long long b[5000][5000];
    long long a[5000];
    int n;
    int main() {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) scanf("%lld",&b[i][j]);
        }
        long long p = round(sqrt(1.0*b[0][1])*sqrt(1.0*b[0][2])*sqrt(1.0*b[1][2]));
        p=p/b[1][2];
        a[0]=p;
        for(int i=1;i<n;i++) a[i]=b[0][i]/a[0];
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        return 0;
    }