#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define fill(m,v) memset(m,v,sizeof(m))
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
//#define long long long
#include<map>
#include<set>
#include<bitset>
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef unsigned long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int D=100;




int main()
{
    int n,k;
    cin>>n>>k;
    int *a=new int[n];
    char c;
    int *b=new int[30];
    for (int i=0;i<n;i++)
    {
        cin>>c;
        a[i]=c-'A';
    }
    int s=0;
    if (k>=3)
    {
        for (int i=1;i<n;i++)
        {
            if (a[i]==a[i-1])
            {
                a[i]=(a[i]+((i<n-1 && (a[i]+1)%k==a[i+1])?k-1:1))%k;
                s++;
            }
        }
        cout<<s<<endl;
        for (int i=0;i<n;i++)
            cout<<(char)('A'+a[i]);
    }
    else
    {
         for (int i=0;i<n;i++)
         {
             if (a[i]==i%2) s++;
         }
         if (s>n/2)
         {
             cout<<n-s<<endl;
             for (int i=0;i<n;i++)
                 cout<<(char)(i%2+'A');
         }
         else
         {
             cout<<s<<endl;
             for (int i=1;i<=n;i++)
                 cout<<(char)(i%2+'A');
         }
         cout<<endl;
    }
    return 0;
}