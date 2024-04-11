#pragma comment(linker,"/STACK:250000000")
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
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define ind second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


int main()
{
    int D[10000002]={0,1,0};
    int Prime[700000];
    int cnt=0;
    int a,n;
    cin>>a>>n;
    int t=a+n-1;
    rep(i,2,t+1)
    {
        if (D[i]==0) D[i]=i,Prime[cnt++]=i;
        for (int j=0;j<cnt && Prime[j]<=D[i] && ll(i)*Prime[j]<=t;j++)
            D[i*Prime[j]]=Prime[j];
    }
    //cout<<cnt<<endl;
    int mxSq[10000000]={0,1,0};
    rep(i,2,t+1)
    {
        int pr=i/D[i];
        mxSq[i]=mxSq[pr];
        if (pr/mxSq[pr]%D[i]==0)
            mxSq[i]*=D[i]*D[i];
    }
    ll res=0;
    rep(i,a,t+1)
        res+=i/mxSq[i];
    cout<<res<<endl;
    return 0;
}

/*
5 1
3 5
4 5
5 5
6 5
7 1
*/