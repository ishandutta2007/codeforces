#include <iostream>
using namespace std;
int main()
{
    int i,n;  char x[101];   int s[101];
    cin>>n;   bool app[27]={0};  bool flag=1;
    for (i=1;i<=n;i++)
    {
        cin>>x[i];
        s[i]=x[i]-64;
        if (s[i]>26)
            s[i]-=32;
    }
    for (i=1;i<=n;i++)
        app[s[i]]=1;
    for (i=1;i<=26;i++)
        if (app[i]==0)
                flag=0;
    if (flag==1)  cout<<"YES";
    else cout<<"NO";
    return 0;
}