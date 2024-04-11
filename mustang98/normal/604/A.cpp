#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;


int main()
{
    double m[5], w[5], rez=0, hs, hu, a=500;
    for (int i=0;i<5;i++) cin>>m[i];
    for (int i=0;i<5;i++) cin>>w[i];
    cin>>hs>>hu;
    rez=hs*100-hu*50;
    for (int i=0;i<5;i++)
    {
        rez+=max((double)0.3*a, (double)((1-(double)m[i]/250)*a-50*w[i]));
        a+=500;
    }
    cout<<rez;
    return 0;
}