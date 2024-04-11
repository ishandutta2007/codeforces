#include<bits/stdc++.h>
#define ex(x) return 0*puts(x);
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    if(n<=3||k==1||k>3||(n==4&&k==2)) ex("-1");
    if(n==4)ex("3\n1 2\n2 3\n3 4");
    n--;
    cout<<n<<endl;
    if(k==2)for(int x=1;x<=n;x++)cout<<x<<' '<<x+1<<endl;
    else
    {
        for(int x=2;x<=n;x++)cout<<"1 "<<x<<endl;
        cout<<n<<' '<<n+1<<endl;
    }
}