#include<bits/stdc++.h>
using namespace std;
int n,k,l,m,o,i,counti;
char a[100010];
int main(){
    cin>>n>>k;
    counti=0;
    scanf("%s",&a);
    sort(a,a+n);
    o=0;
    a[n]='[';
    l=1000000;
    for(i=1;i<=n;i++)
    {
        if(a[i]-a[i-1]>0)
        {
            m=i-o;
            o=i;
            if(m<l)
            {
                l=m;
            }
            counti++;
        }
    }
    if(counti!=k)
    {
        l=0;
    }
    cout<<l*k;
}