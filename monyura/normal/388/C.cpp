#pragma comment(linker,"/STACK:128000000")
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cd;

#define rep(x,y,z) for (int x = (y), e##x = (z); x < e##x; x++)
#define all(c) (c).begin(), (c).end()
const double PI = acos(-1.0);

int lastId = 2;
vector<int> inc[2001];
int S = 0, T = 1;


int block[50];
void build(int len)
{
    inc[S].push_back(lastId);
    lastId++;
    for (int i = 0; i < len; i++)
    {
        block[i] = lastId - 1;
        inc[lastId-1].push_back(lastId);
        inc[lastId-1].push_back(lastId+1);
        inc[lastId].push_back(lastId+2);
        inc[lastId+1].push_back(lastId+2);
        lastId += 3;
    }
    block[len] = lastId-1;
    inc[lastId-1].push_back(T);
}

void addPath(int to, int curr, int len)
{
    inc[S].push_back(lastId);
    ++lastId;
    rep(i,0,2*(len-curr)-1)
    {
        inc[lastId-1].push_back(lastId);
        ++lastId;
    }
    inc[lastId-1].push_back(to);
}

ll getCnt(int n)
{
    ll res = 0;
    for (int i =2; i*i<=n;i++)
    {
        if (n%i==0)
            res +=i;
        while (n%i == 0)
        {
            n/=i;
//            res+= i;
        }

    }
    return res;
}

char Ans[2002][2002]={0};
void run()
{
//    cout<<(1<<29)-1<<endl;
//    rep(i,0,10000)
//    {
//        int n = 1000000000-i;
//        ll cnt = getCnt(n);
//        if (cnt>1000)
//        {
//            cout<<cnt<<' '<<n<<endl;
//        }
//    }
    int n;
    cin>>n;
    int res[2] = {0};
    int A[200]={0};
    int cnt = 0;
    rep(i,0,n)
    {
        int s;
        scanf("%d",&s);
        rep(j,0,s)
        {
            int a;
            scanf("%d",&a);
            if ((s&1) && (s/2)==j)
                A[cnt++] = a;
            else if (j < s/2)
                res[0] += a;
            else
                res[1] += a;
        }
    }
    sort(A,A+cnt,greater<int>());
    rep(i,0,cnt)
    res[i&1] += A[i];
    cout<<res[0]<<' '<<res[1]<<endl;
//    int k;
//    cin>>k;
//    int len = 0;
//    rep(i,0,31)
//    if ((k>>i)&1)
//    {
//        len = i;
//    }
//    build(len);
//    rep(i,0,len)
//    if ((k>>i)&1)
//    {
//        addPath(block[len-i],i, len);
//    }
//    int n = lastId;
//    cout<<n<<endl;
//    rep(i,0,n)
//    rep(j,0,n)
//    Ans[i][j] = 'N';
//    rep(i,0,n)
//    rep(j,0,inc[i].size())
//    {
//        int a= i;
//        int b = inc[i][j];
//        Ans[a][b] = Ans[b][a] = 'Y';
//    }
////    rep(i,0,n)
////    rep(j,0,inc[i].size())
////    {
////        cout<<i+1<<' '<<inc[i][j]+1<<endl;
////    }
////
//    rep(i,0,n)
//    puts(Ans[i]);
}

//#define problem "finals"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t start = clock();
#else
#ifdef problem
    freopen(problem".in","r",stdin);
    freopen(problem".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf("============\nTime: %.3lf\n",(clock() - start)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}