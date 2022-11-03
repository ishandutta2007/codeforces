#include <iostream>
using namespace std;

int x[300100],j[300100];
int bad(int a)
{
    if(x[a]==a)
        return a;
    else
        {
            x[a]=bad(x[a]);
            return x[a];
        }
}

int main()
{
    int n,m;
    cin>> n >> m;
    for(int i=1;i<=n+1;i++)
        x[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a=bad(a);
        while(a<=b)
        {
            if(a!=c)
                {
                    j[a]=c;
                    x[a]=bad(a+1);
                }
            a++;
            a=bad(a);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<j[i]<<" ";
}