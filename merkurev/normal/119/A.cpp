#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int gcd(int x,int y)
{
    if (x) return(gcd(y%x,x)); else return y;
}
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int a,b,n;
    cin>>a>>b>>n;
    for (int i=0;i<1000;i++)
    {
        int x=gcd(a,n);
        if (x<=n) n-=x;
        else
        {
            cout<<1;
            return 0;
        }
        x=gcd(b,n);
        if (x<=n) n-=x;
        else
        {
            cout<<0;
            return 0;
        }
    }
    return 0;
}