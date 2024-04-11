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

    bool compare(pair<int,int> t1,pair<int,int> t2)
    {
        if (t1.first>t2.first) return true;
        else return false;
    }
    lli n,k;
    lli b;
    bool *used;
    int *a;
    pair<int,int> *m;
    int main()
    {
        cin>>n>>k>>b;
        a=new int[n];
        used=new bool[n];
        m=new pair<int,int>[n];
    for (int i=0;i<n;i++)
    {
        cin>>m[i].first;
        m[i].second=i;
        used[i]=false;
    }
    sort(m,m+n-1,compare);
    int last=n-1;
    int bestnum;
    int first=0;
    int maxsum=0;
    if (k!=n)
    {
    for (int i=0;i<k-1;i++)
        maxsum+=m[i].first;
    if (b<maxsum)
    {
        cout<<1;
        return 0;
    }
//  cout<<maxsum<<endl;
    int min1=n-1;
    for (int i=k-1;i<n;i++)
        if (m[i].second<min1 && m[i].first>b-maxsum)
            min1=m[i].second;

    //cout<<min1+1<<endl;

    maxsum+=m[k-1].first;
    int min2=n-1;
    if (b<maxsum)
//      cout<<maxsum<<endl;
    for (int i=0;i<k;i++)
    {
        if (m[i].second<min2)
            min2=m[i].second;
    }
//  cout<<min2+1<<endl;
    cout<<min(min1,min2)+1;
    




    }
    
    return 0;
}