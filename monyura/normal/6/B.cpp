#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

void run()
{
    int n,m;
    char c;
    cin>>n>>m>>c;
    char A[200][200];
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    rep(i,0,n)
    scanf("%s",A[i]);
    set<char> st;
    rep(i,0,n)
    rep(j,0,m)
    if (A[i][j] == c)
        rep(k,0,4)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx>=0 && nx < n && ny>=0 && ny < m && A[nx][ny] !='.')
            st.insert(A[nx][ny]);
    }
    st.erase(c);
    cout<<st.size()<<endl;
    
}


//#define prob "path"


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}