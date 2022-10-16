#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a,b,c,d,i,j;
    cin>>a>>b>>c>>d;
    a--;
    b--;
    c--;
    d--;
    cout<<50<<' '<<50<<'\n'; // a<- b  |  b<- c | c<- d | d<- a;
    for(i=1;i<=50;++i)
    {
        for(j=1;j<=50;++j)
        {
            if(i<=25 && j<=25) // zona A
            {
                if(i%2==1 || j%2==1)
                    cout<<'A';
                else
                {
                    if(b)
                    {
                        cout<<'B';
                        b--;
                    }
                    else
                        cout<<'A';
                }
            }
            else if(i<=25 && j>25) // zona B
            {
                if(i%2==1 || j%2==1 || j==26)
                    cout<<'B';
                else
                {
                    if(c)
                    {
                        cout<<'C';
                        c--;
                    }
                    else
                        cout<<'B';
                }
            }
            else if(i>25 && j<=25) // zona C
            {
                if(i%2==1 || j%2==1 || i==26)
                    cout<<'C';
                else
                {
                    if(d)
                    {
                        cout<<'D';
                        d--;
                    }
                    else
                        cout<<'C';
                }
            }
            else // zona D
            {
                if(i%2==1 || j%2==1 || i==26 || j==26)
                    cout<<'D';
                else
                {
                    if(a)
                    {
                        cout<<'A';
                        a--;
                    }
                    else
                        cout<<'D';
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}