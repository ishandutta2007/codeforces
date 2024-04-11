#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

vector <int> m;
ll n, k1=0,r=1;

void func(int a)
{

}

int main()
{
    int a;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        k1+=a;
        if (a) m.push_back(i);
    }
    if (!k1) {cout<<0; return 0;}
    for (int i=1;i<m.size();i++) r*=(m[i]-m[i-1]);
    cout<<r;
    return 0;
}