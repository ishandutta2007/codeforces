#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long m,w,ans=0;
    char n;
    cin>>m>>n;
    if((m-1)%4!=0&&(m-1)%2==0) m=m-2;
    if(m%4==0) m=m-2;
    w=m%4;
    ans=((m-w)/4)*16;if(w==2) ans=ans+7;
    if(n=='a') ans+=4;if(n=='b') ans+=5;
    if(n=='c') ans+=6;if(n=='d') ans+=3;
    if(n=='e') ans+=2;if(n=='f') ans+=1;
    cout<<ans<<endl;
    return 0;
}