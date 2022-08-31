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

typedef long long lli;
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
    string s;
    int k,n;
    cin>>k>>s;
    int a[200];
    for (int i=0;i<200;i++)
        a[i]=0;
    for (int i=0;i<s.length();i++)
        a[s[i]]++;
    bool e=true;
    string res="";
    for (int i=0;i<200;i++)
    {
        if (a[i]>0)
        {
            if (a[i]%k!=0) {e=false;break;}
            for (int j=0;j<a[i]/k;j++)
                res+=(char) i;
        }
    }
    if (!e) { cout<<-1<<endl; return 0;}
    for (int i=0;i<k;i++)
        cout<<res;
    cout<<endl;
    return 0;
}