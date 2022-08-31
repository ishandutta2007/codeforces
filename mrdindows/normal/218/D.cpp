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
//#define mp(x,y) make_pair((x),(y))
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

int main()
 {
    int n,r;
    cin>>n>>r;
    int min=n;
    lli f1=1;
    lli f2=1;
    for (int i=0;i<n-1 && f2<r;i++)
    {
        f1=f2+f1;
        swap(f1,f2);
    }
    if (r>f2) {cout<<"IMPOSSIBLE"<<endl; return 0;}
    //vector<int>result;
    int *res=new int[n];
    int size=-1;
    if (n==r && n==1) {cout<<0<<endl<<"T"<<endl;return 0;}
    if (n==r && n==2) {cout<<0<<endl<<"TB"<<endl;return 0;}
    int *p=new int[n];
    for (int i=r/2;i>=1;i--)
    {
    //  vector<int> v;
        int num=1;
        p[0]=1;
    //  v.push_back(1);
        int a=r-i;
        int b=i;
        int k=1;
        int err=0;
        while (a+b>2 && a*b!=0)
        {
        //  cout<<"a="<<a<<" b="<<b<<endl;
            if (b==1) {
            k+=a-1;err+=a-2;//v.push_back(a-1);
            p[num++]=a-1;
            a=1;b=0;break;}

            
            int c=a/b;
        //  if (n-k-1>c+b) break;
            k+=c;
            if (k>n-1) break;
            err+=c-1;
            if (err>=min) break;
    //      v.push_back(c);
            p[num++]=c;
            a=a%b;
            swap(a,b);
        }
        if (a==1 && b==0 && err<min && k==n-1)
        {   
    //      cout<<k<<endl;
    //      result=v;
    //      res=p;
            for (int j=0;j<num;j++)
                res[j]=p[j];
            size=num;
            min=err;
            if (err==0) break;  
        }
    }
    if (min<n)
    {
        cout<<min<<endl;
        cout<<"T";
        bool e=false;
    /*  for (int i=result.size()-1;i>=0;i--)
        {
            for (int j=0;j<result[i];j++)
                cout<<((e)?'T':'B');
            e=!e;
        }*/
        for (int i=size-1;i>=0;i--)
        {
            for (int j=0;j<res[i];j++)
                cout<<((e)?'T':'B');
            e=!e;
        }
        cout<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;
  //  system("pause");
    return 0;
 }