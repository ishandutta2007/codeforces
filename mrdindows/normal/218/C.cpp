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
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
//#define long long long
#include<map>
#include<set>
#include<bitset>
//typedef pair<int,int> pii;
//typedef vector<int> vi;
//typedef vector<pii> vpii;
#define mod 1000000007
 typedef long long lli;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int D=100;

using namespace std;
int n;
vector<int> g[1000];
bool used[1000];
vector<int> comp;
 
void dfs (int v) {
    used[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}
 int counts=0;
void find_comps() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (! used[i]) {
            comp.clear();
            dfs (i);
            counts++;
            /*cout << "Component:";
            for (size_t j=0; j<comp.size(); ++j)
                cout << ' ' << comp[j];
            cout << endl;*/
        }
}
int main()
 {
    cin>>n;
    int *x=new int[n];
    int *y=new int[n];
    bool **a=new bool*[n];
    for (int i=0;i<n;i++)
    {
        a[i]=new bool[n];
        for (int j=0;j<n;j++)
            a[i][j]=false;
        cin>>x[i]>>y[i];
    }
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (x[i]==x[j] || y[i]==y[j]) {g[i].push_back(j);g[j].push_back(i);}
    find_comps();
    cout<<counts-1<<endl;
    //system("pause");
    return 0;
 }