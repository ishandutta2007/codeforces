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

        int main()
        {   
            bool last=true;
            bool e=false;
            char c;
            vector<char> a,b;
            a.clear();
            b.clear();
            bool th=false;
            vector<char> v;
            v.clear();
            while (scanf("%c",&c)!=EOF)
            {
                if (c=='\n')
                {
                    if (last || th)
                    {
                        if (!last)
                        for (int i=0;i<a.size();i++)
                        {
                            if (a[i]!=' ')
                                cout<<a[i];
                        }
                        else
                        for (int i=0;i<a.size();i++)
                            cout<<a[i];
                    }
                    else
                    {
                        for (int i=0;i<a.size();i++)
                        {
                            if (a[i]!='\n' && a[i]!=' ')
                                cout<<a[i];
                        }
                    }
                    e=false;last=th;
                    th=false;
                    a=b;
                    a.push_back(c);
                    b.clear();
                }
                else
                if ((!e) && c!=' ')
                {
                    e=true;
                    if (c=='#')
                    {
                        th=true;
                    }
                    b.push_back(c);
                }
                else
                    b.push_back(c);

            }
            if (last || th)
                    {
                        if (!last)
                        for (int i=0;i<a.size();i++)
                        {
                            if (a[i]!=' ')
                                cout<<a[i];
                        }
                        else
                        for (int i=0;i<a.size();i++)
                            cout<<a[i];
                    }
                    else
                    {
                        for (int i=0;i<a.size();i++)
                        {
                            if (a[i]!=' ')
                                cout<<a[i];
                        }
                    }

            return 0;
        }