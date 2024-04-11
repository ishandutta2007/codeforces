#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    ll a, h, n,w,ch=1;
    cin>>n>>h>>w;
    if (n>h*w) {cout<<-1; return 0;}
    if (w%2==1)
    {
        for (int i=0;i<h;i++){
        for (int j=0;j<w;j++) {cout<<(ch<=n?ch:0)<<' '; ch++;}
        cout<<endl;}
    }
    else
    for (int i=0;i<h;i++)
    {
        if (i%2==0) for (int j=0;j<w;j++) {cout<<(ch<=n?ch:0)<<' '; ch++;}
        else {for (int j=w-1;j>=0;j--) {cout<<(ch+j<=n?ch+j:0)<<' ';}; ch+=w;}
        cout<<endl;
    }
    return 0;
}