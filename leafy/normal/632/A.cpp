#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p;
string s[60];
int main()
{
    cin>>n>>p;
    p>>=1;
    for (int i=1;i<=n;i++) cin>>s[i];
    ll ans=0,num=0;
    for (int i=n;i>=1;i--){
        num<<=1;
        if(s[i]=="halfplus") num++;
        ans+=num;
    }
    printf("%lld", ans*p);
}