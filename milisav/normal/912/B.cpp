#include<bits/stdc++.h>
using namespace std;
long long int n,k;
long long int l=1;
int main()
{
    cin>>n>>k;
    while(l<=n) l=l<<1;
    if(k==1) cout<<n<<endl;
    else cout<<l-1<<endl;
    return 0;
}