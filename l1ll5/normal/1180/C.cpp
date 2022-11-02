#include <cmath>
#include <queue>
#include <deque>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q;
deque<int> a;
int AA[N],BB[N];
int aa[N],bb[N];
ll m;
int main()
{
    n=read(),q=read();
    int x;
    for(int i=1;i<=n;i++)x=read(),a.push_back(x);
    for(int i=1;i<=n-1;i++)
    {
        int A=a.front();a.pop_front();
        int B=a.front();a.pop_front();
        AA[i]=A,BB[i]=B;
        if(A>B)a.push_front(A),a.push_back(B);
        else swap(A,B),a.push_front(A),a.push_back(B);
    }
    for(int i=1;i<=n-1;i++)
    {
        int A=a.front();a.pop_front();
        int B=a.front();a.pop_front();
        aa[i]=A,bb[i]=B;
        if(A>B)a.push_front(A),a.push_back(B);
        else swap(A,B),a.push_front(A),a.push_back(B);
    }
    while(q--)
    {
        cin>>m;
        if(m<=n-1)
        printf("%d %d\n",AA[m],BB[m]);
        else
        {
            m=m-(n-1);
            m=m%(n-1);
            if(m==0)m=n-1;
            printf("%d %d\n",aa[m],bb[m]);
        }
    }
}