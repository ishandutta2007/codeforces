#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
LL a[MAXN],ans[MAXN],pre;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]; 
    ans[n]=a[n],pre=a[n];
    for(int i=n-1;i>=1;i--) ans[i]=pre+a[i],pre=ans[i]-pre;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}