#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int modo = 998244353;
struct matrix
{
    int a[2][2];
    int * operator [] (const int x)
    {
        return a[x];
    }
    int * operator [] (const int x) const
    {
        return (int *) a[x];
    }
    matrix (int t = 1)
    {
        a[0][0] = t;
        a[1][0] = 0;
        a[0][1] = 0;
        a[1][1] = t;
    }
    friend matrix operator * (const matrix &a, const matrix &b)
    {
        matrix c(0);
        c[0][0] = ((long long)a[0][0] * b[0][0] + (long long)a[0][1] * b[1][0]) % modo;
        c[0][1] = ((long long)a[0][0] * b[0][1] + (long long)a[0][1] * b[1][1]) % modo;
        c[1][0] = ((long long)a[1][0] * b[0][0] + (long long)a[1][1] * b[1][0]) % modo;
        c[1][1] = ((long long)a[1][0] * b[0][1] + (long long)a[1][1] * b[1][1]) % modo;
        return c;
    }
};
matrix zero(0);
matrix one(0);
vector<int> v[300005];
int val[300005];
matrix p[1<<20];
void build_tree(int num,int l,int r)
{
    if (l == r-1)
    {
        p[num] = zero;
        if (l == 0)
        {
            p[num] = matrix(1);
        }
        return;
    }
    int mid = (l + r) / 2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    p[num] = p[num*2+1] * p[num*2+2];
}
void change(int num,int l,int r,int x,matrix &res)
{
    if (l == r-1)
    {
        p[num] = res;
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid)
    {
        change(num*2+1,l,mid,x,res); 
    }
    else
    {
        change(num*2+2,mid,r,x,res);
    }
    p[num] = p[num*2+1] * p[num*2+2];
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    zero[0][0] = 3;
    zero[0][1] = 0;
    zero[1][0] = 1;
    zero[1][1] = 2;
    one[0][0] = 1;
    one[0][1] = 2;
    one[1][0] = 1;
    one[1][1] = 2;
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        r++;
        v[l].push_back(i);
        v[r].push_back(i);
    }
    build_tree(0,0,n);
    int ans = 0;
    for (i=0;i<=300000;i++)
    {
        int j;
        for (j=0;j<(int)v[i].size();j++)
        {
            if (v[i][j] == 0)
            {
                val[0] ^= 1;
            }
            else
            {
                if (val[v[i][j]] == 0)
                {
                    change(0,0,n,v[i][j], one);
                }
                else
                {
                    change(0,0,n,v[i][j], zero);
                }
                val[v[i][j]] ^= 1;
            }
        }
        ans = (ans + p[0][val[0]][1]) % modo;
    }
    printf("%d\n",ans);
    return 0;
}