#include<iostream>

using namespace std;

int n;
int x[10000],y[10000];

int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    int ans=0;
    for (int i=1;i<=n;++i)
    {
        int A,B,C,D;
        A=B=C=D=0;
        for (int j=1;j<=n;++j)
        {
            if (x[j]<x[i]&&y[i]==y[j]) ++A;
            if (x[j]>x[i]&&y[i]==y[j]) ++B;
            if (x[i]==x[j]&&y[i]<y[j]) ++C;
            if (x[i]==x[j]&&y[i]>y[j]) ++D;
        }
        if (A&&B&&C&&D) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}