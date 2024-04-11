//#pragma comment(linker,"/STACK:62000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
    ll mx=-1,mn=5e18;
    ll a,b,c,c2;
    ll n;
    cin>>n;
    ll curr;
    for (int i=1;i*i<=n;i++)
        if (n%i==0)
        {
            a=i;
            b=n/i;
            mx=max(mx,(a+1)*(b+2)*3-a*b);
            curr=(b+2)*3;
            for (int j=1;j*j<=b;j++)
                if (b%j==0)
                    if (ll(j+2)*(b/j+2)<curr) curr=ll(j+2)*(b/j+2);
            mn=min(mn,(a+1)*curr-a*b);
            swap(a,b);
            mx=max(mx,(a+1)*(b+2)*3-a*b);
            curr=(b+2)*3;
            for (int j=1;j*j<=b;j++)
                if (b%j==0)
                    if (ll(j+2)*(b/j+2)<curr) curr=ll(j+2)*(b/j+2);
            mn=min(mn,(a+1)*curr-a*b);
            
        }
    cout<<mn<<' '<<mx<<endl;
    return 0;
} 

/*

*/