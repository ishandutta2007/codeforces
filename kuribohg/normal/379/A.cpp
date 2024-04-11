#include<iostream>
using namespace std;
int used,b,ans;
int main()
{
    cin>>ans>>b;
    used=ans;
    while(used>=b)
    {
        ans+=used/b;
        used=used%b+used/b;
    }
    cout<<ans<<endl;
    return 0;
}