#include <iostream>

using namespace std;

int main()
{
    int m[110]={0}, n, M,a,k;
    cin>>n>>M;
    for (int i=0;i<n;i++)
    {
        cin>>k;
        for (int i=0;i<k;i++) {cin>>a;m[a]=1;}
    }
    for (int i=1;i<=M;i++) if (m[i]==0) {cout<<"NO"; return 0;}
    cout<<"YES";
    return 0;
}