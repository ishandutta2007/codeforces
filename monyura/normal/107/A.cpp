    #pragma comment(linker,"/STACK:64000000")
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
    #include <iomanip>
    #include <functional>

    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    typedef unsigned int ui;
    typedef short int si;
    typedef long double ld;
    typedef pair<int,int> pii;
    #define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

    const double PI=acos(-1.0);

    template<class T> inline T SQR(T a){return a*a;}


    int *g;
    int *d;
    int *to;
    int *in;

    int dfs(int k)
    {
            if (g[k]==-1) return 1e9;
            int nxt=dfs(g[k]);
            to[k]=to[g[k]];
            return min(d[k],nxt);
    }

    int main()
    {
            int n,m;
            cin>>n>>m;
            g=new int [n];
            d=new int[n];
            to =new int[n];
            in =new int[n];
            memset(in,0,4*n);
            rep(i,0,n)
            {
                    g[i]=-1;
                    to[i]=i;
            }
            rep(i,0,m)
            {
                    int a,b,D;
                    scanf("%d%d%d",&a,&b,&D);
                    a--;
                    b--;
                    in[b]++;
                    g[a]=b;
                    d[a]=D;
            }
            int f,t,best=0;
            int cnt=0;
            rep(i,0,n)
            {
                    if (in[i]==0 && g[i]!=-1) cnt++;
            }
            printf("%d\n",cnt);
            rep(i,0,n)
            {
                    if (in[i]==0 && g[i]!=-1)
                    {
                            int curr=dfs(i);
                            printf("%d %d %d\n",i+1,to[i]+1,curr);
                    }
            }
            return 0;
    }

    /*
    1000000 2000000
    1000000 2000000

    0 2
    1 0
    */