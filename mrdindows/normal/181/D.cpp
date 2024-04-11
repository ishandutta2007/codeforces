#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
//#include <math.h>
//#include <vector.h>
//#include <string>
typedef long long ll;   
using namespace std;

ll step(ll x,ll y)
{
    if (y==1) return x;
    if (y==0) return 1;
    return ((step((x*x)%(1000000007),y/2)%(1000000007))*(1+(x-1)*(y%2)))%(1000000007);
}
int main()
{
  //  cout<<step(2,40);
    ll n=0,k,t=0,sum=0;
    string a,b;
    cin>>a>>b>>k;
    n=a.length();
    for (int i=0;i<n;i++)
        if (a[i]==b[0])
        {
            bool e=true;
            for (int j=1;j<n;j++)
            {
                if (a[(i+j)%n]!=b[j])
                {e=false;break;}
            }
            if (e) t++;
        }
    if (t==0 || t==1 && a==b && k==1) cout<<0;
    else    
    {
        sum=0;
        if (a==b) 
        {
            sum=1;
        }
        
        for (int i=0;i<k;i++)
            sum=((ll)1000000007+step(n-1,i)*t-sum)%(ll)1000000007;
        cout<<sum;
    }

   // system("Pause");
    return 0;

}