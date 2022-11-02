# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;

long long a[4000000]; int n; long long ans=0;
bool cmp(const int&i,const int&j){return i>j;} 
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%I64d",a+i);
    sort(a,a+n,cmp);
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    while(n>0){ans+=a[n-1];n>>=2;}
    cout<<ans<<endl;
    return 0;
}