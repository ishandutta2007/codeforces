#include<bits/stdc++.h>
using namespace std;

long long a,b,c,i,n;
long long num[105];
long long num2[105];

int main() {
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>num2[i];
    }
    for(i=1;i<=n;i++)
    {
        if(num[i]==0 && num2[i]==1)
        {
            b++;
        }
        if(num[i]==1 && num2[i]==0)
        {
            a++;
        }
    }
    if(a==0) {cout<<-1;}
    else if((b+1)%a==0){cout<<(b+1)/a;} else {cout<<(b+1)/a+1;}

}