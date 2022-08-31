#include <iostream>
#include <math.h>
#include <algorithm>
typedef unsigned long long lli; 
using namespace std;
const lli mod=1000000007;   
int a,b,c;
double x,y,z;
double s;
double f(double x)
{
    double S=s-x;
    double k=b/(double)c;
    y=S*k/(k+1);
    z=S-y;
    return pow(x,a)*pow(y,b)*pow(z,c);
}
int main()
{


    cin>>s>>a>>b>>c;

    if (b==0 && c==0)
    {
            cout<<fixed;
    cout.precision(1);
        cout<<(double)s;
        cout<<" 0.0 0.0";
    }
    else
        if (a==0 && c==0)
        {
            cout<<"0.0 ";
    cout<<fixed;
    cout.precision(1);
            cout<<(double)s<<" 0.0";
        }
        else
            if (a==0 && b==0)
        {

            cout<<"0.0 0.0 ";
                            cout<<fixed;
    cout.precision(1);
    cout<<(double) s;
        }
            else
            {
                if (a==0)
                {
                    x=0;
                    double k=b/(double)c;
                    y=s*k/(k+1);
                    z=s-y;
                }
                else
                    if (b==0)
                    {
                        y=0;
                    double k=a/(double)c;
                    x=s*k/(k+1);
                    z=s-x;
                    }
                    else if (c==0)
                    {
                        z=0;
                                            double k=a/(double)b;
                    x=s*k/(k+1);
                    y=s-x;
                    }
                    else
                    {
                        x=s*a/(double)(a+b+c);
                        y=s*b/((double)a+b+c);
                        z=s*c/((double)a+b+c);
                    }
                    cout.precision(20);
                    cout<<x<<" "<<y<<" "<<z<<endl;
            }
        cin>>s;
    return 0;
}