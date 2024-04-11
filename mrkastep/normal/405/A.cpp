#include <stdio.h>
#include <algorithm>

int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","rt",stdin);
 freopen("output.txt","wt",stdout);
 #endif
 int a[100],n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",&a[i]);
 std::sort(a,a+n);
 for(i=0;i<n;i++) printf("%d ",a[i]);
}