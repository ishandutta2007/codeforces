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
//#define long long long
#include<map>
#include<set>
using namespace std;
#define mod 1000000007
 typedef long long lli;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
 {
    int n;
    cin>>n;
    int a[10];
    fill(a,0);
    int x;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        a[x]++;
    }
    if (a[0]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        int sum=0;
        for (int i=1;i<10;i++)
            sum=(sum+i*a[i])%3;
        if (sum!=0)
        {
            bool e=false;
            for (int i=0;i<3;i++)
                if (a[i*3+sum]>0)
                {
                    a[i*3+sum]--;
                    n--;
                    e=true;
                    break;
                }
            if (!e)
            {
                int k=2;
                for (int i=0;i<3;i++)
                if (a[i*3+3-sum]>0)
                {
                    int c=min(k,a[i*3+3-sum]);
                    a[i*3+3-sum]-=c;
                    k-=c;
                    if (k==0)
                    {
                        e=true;
                        n-=2;
                        break;
                    }
                }
            }
            if (!e || n==0)
            {
                cout<<-1<<endl;
                return 0;
            }
        }

        int t=0;
            for (int i=9;i>=0;i--)
            {
                if (i==0 && t==0)
                {
                    cout<<"0"<<endl;
                    return 0;
                }
                for (int j=0;j<a[i];j++)
                {
                    t+=i;
                    cout<<i;
                }
            }


    }
    return 0;
 }