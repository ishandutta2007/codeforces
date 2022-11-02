#pragma comment(linker,"/STACK:16777216")
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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

typedef vector<int> vi;
struct data
{
        vi vec;
        int ind;
};

bool operator<(const data& a,const data& b)
{
        return a.vec>b.vec;
}

int main()
{
        int n;
        cin>>n;
        if (n==2)
        {
                int k;
				cin>>k;
				int a;
				cin>>a;
				printf("1 %d\n%d",a,k-1);
				rep(i,1,k)
				{
					scanf("%d",&a);
					printf(" %d",a);
				}
                return 0;
        }
        int B[201];
        vi *A=new vi[n*n];
        data Cnt[201];
        rep(i,0,n*(n-1)>>1)
        {
                int k;
                scanf("%d",&k);
                A[i].reserve(k);
                rep(j,0,k)
                {
                        int b;
                        scanf("%d",&b);
                        A[i].push_back(b);
                        Cnt[b].vec.push_back(i);
                        Cnt[b].ind=b;
                }
        }
        sort(Cnt,Cnt+201);
        int res=0;
        vi ans[201];
        rep(i,0,201)
                if (Cnt[i].vec.size()!=0)
                {
                        if (i!=0 && Cnt[i].vec!=Cnt[i-1].vec) res++;
                        ans[res].push_back(Cnt[i].ind);
                }
        res++;
        rep(i,0,res)
        {
                printf("%d",ans[i].size());
                rep(j,0,ans[i].size())
                        printf(" %d",ans[i][j]);
                printf("\n");
        }
        return 0;
}