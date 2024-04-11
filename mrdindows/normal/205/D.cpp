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
    #define y0 stupid_cmath_make_me_cry
    #define tm stupid_ctime
    //#define long long long
    #include<map>
    #include<set>
    using namespace std;
    #define mod 1000000007
    typedef long long lli;
    typedef pair<int,int> pii;
    typedef pair<int,pair<int,int>> pipii;
    int k=2124679;

    lli f(lli x)
    {
        lli p=x%10113;
        lli t=x%324;
        lli q=x/11;
        lli r;
       r=((x/10-p+k)%(t+2)+q+(x*2-44+k)%763431)%k;
       while (r<0) r+=k;
       return r;
    }
    int main()
    {
        int *a=new int[k+1];
        int *b=new int[k+1];
        for (int i=0;i<k;i++)
            a[i]=b[i]=0;
        int n;
        cin>>n; 
        for (int i=0;i<n;i++)
        {
            lli x,y;
            cin>>x>>y;
            a[f(x)]++;
            if (y!=x)
            b[f(y)]++;
        }
        int min=n+1;
        for (int i=0;i<k;i++)
            if (a[i]+b[i]>=(n+1)/2)
                if ((n+1)/2-a[i]<min)
                    min=(n+1)/2-a[i];
        if (min<0) cout<<0;
        else 
       if (min>n) cout<<-1; else cout<<min; 
        delete[k+1] a;
        delete[k+1] b;
        return 0;
    }