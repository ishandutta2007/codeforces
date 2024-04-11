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
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x));
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]));
#define random(x) (((rand()*25)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
#include<map>
#include<set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#pragma comment(linker,"/STACK:256000000")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef pair<int,int> pii;
typedef pair<int, bool> pib;

#define maxll 0x7fffffffffffffffLL
#define mod 1073741824//1000000009

#pragma comment(linker,"/STACK:256000000")
#define mod 1000000009
#define maxll 0x7fffffffffffffffLL
int b[4000][4000];
int c[4000][4000];
int main()
{
    int n;
//  int x,y,c;
//  scanf("%d%d%d%d",&n,&x,&y,&c);

    scanf("%d",&n);
    int *a=new int[n];
    map<int , int> nums;
    int *q=new int[n];
    int curnum=0;
    bool *e=new bool[n];
    map<pair<int,int>, pair<int,bool> > *m=new map<pair<int,int>, pair<int,bool> >[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if (nums.find(a[i])==nums.end())
        {
            nums[a[i]]=curnum++;
        }
        q[i]=nums[a[i]];
        e[i]=false;
        for (int j=0;j<n;j++)
            c[i][j]=(i==j)?1:1,b[i][j]=1;
    }
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        int k=q[i];
        for (int j=0;j<i;j++)
        {
            int r=q[j];
            if (b[k][r]==1 && !e[r])
            {
                if (r==k)
                {
                    c[r][k]++;
                }
                else
                {
                    b[k][r]=-1;
                    b[r][k]=1;
                    c[k][r]++;
                    c[r][k]++;
                }
                e[r]=true;
            }
        }
        for (int j=0;j<=i;j++)
        {
            e[j]=false;
        }
    }
    cout<<*max_element(c[0],c[n-1]+n)<<endl;
    return 0;    
}