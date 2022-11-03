#include<iostream>
using namespace std;
int main()
{
    long long l,r,k,a=1,b[40],j=0;
    b[0]=0;
    cin>>l>>r>>k;
    if(l>1  && r<k) {cout<<"-1"; return 0;}
    while(a<l)
        a*=k;
    while(a<=r && (a%k==0 || a==1))
    {
        cout<<a<<" ";
        b[0]=a;
        a*=k;
        if(a<0)
            break;
    }
    if(b[0]==0)
    cout<<"-1";
}