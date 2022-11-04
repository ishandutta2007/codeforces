#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1010],b[1010],fl;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
    for(int i=1;i<=n;i++) if(a[i] != b[i]) fl=1;
    if(fl) return !printf("rated");

    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i] < a[j]) return !printf("unrated");

    printf("maybe");
}