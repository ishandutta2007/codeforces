# include <iostream>
# include <cstdio>
using namespace std;

int n,t=0,ans=0;
int main()
{
    cin >> n;
    int x;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        t+=x;
    }
    for(int i=1;i<=5;i++)
        if((t+i)%(n+1)!=1)
            ans++;
    cout<<ans<<endl;
}