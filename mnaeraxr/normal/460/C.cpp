/*
    author:     MarX
    school:     UH
*/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define oo 1000000000
#define MOD 1000007
#define MAX 100010

struct N{
    LL v,l;
} ST[MAX << 2];
LL F[MAX];

void build(int p, int b, int e)
{
    if (b == e)
        ST[p].v = F[b], ST[p].l = 0;
    else
    {
        int mid = (b + e) / 2;
        int left = 2*p;
        int right = 2*p + 1;
        build(left,b,mid);
        build(right,mid + 1,e);
        ST[p].v = min(ST[left].v,ST[right].v);
        ST[p].l = 0;
    }
}

void down(int p, int v)
{
    ST[p].v += v;
    ST[p].l += v;
}

void update(int p, int b, int e, int x, int y)
{
    if (x <= b && e <= y)
    {
        ST[p].v++;
        ST[p].l++;
    }
    else
    {
        int mid = (b + e) / 2;
        int left = 2*p;
        int right = 2*p + 1;
        
        if (ST[p].l > 0)
        {
            down(left,ST[p].l);
            down(right,ST[p].l);
            ST[p].l = 0;
        }

        if (y <= mid)
            update(left,b,mid,x,y);
        else if (mid + 1 <= x)
            update(right,mid + 1,e,x,y);
        else
        {
            update(left,b,mid,x,y);
            update(right,mid + 1,e,x,y);
        }
        ST[p].v = min(ST[left].v,ST[right].v);
    }
}

int getMin(int p, int b, int e)
{
    if (b == e)
        return b;
    int mid = (b + e) / 2;
    int left = 2*p;
    int right = left + 1;
    if (ST[left].v <= ST[right].v)
        return getMin(left,b,mid);
    return getMin(right,mid + 1,e);
}

int main()
{
    int n,m; 
    LL w; 
    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i)
        cin >> F[i];
    build(1,0,n - 1);
    for (int i = 0; i < m; ++i)
    {
        int pos = getMin(1,0,n - 1);
        if (pos + w >= n)
            pos = n - w;
        update(1,0,n - 1,pos, pos + w - 1);
        //print(1,0,n - 1); cout << endl;
    }
    cout << ST[1].v << endl;
}