#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


pair <int,pair<int,int>> q[100500];

int m[100500],v[100500];

int main () {
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "wt", stdout);

    int k,n,h;
    scanf("%d%d%d",&n,&k,&h);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    for (int i=0;i<n;i++)
        q[i]=make_pair(m[i],make_pair(v[i],i+1));
    sort(q,q+n);
    double tl=0;
    double tr=1e10;
    double eps=1e-20;
    for (int z=0;z<120;z++)
    {
        double t=(tr+tl)/2.;
        int curh=1; 
        for (int i=0;i<n && curh<=k;i++)
        {
            int curv=q[i].second.first;
            double curl = curh * h;
            double curt = curl / curv;
            if (curt<=t+eps)
            {
                curh++;
            }
        }
        if (curh>k)
        {
            tr=t;
        }
        else
        {
            tl=t;
        }
    }
    double t=tr;
    int curh=1; 
    for (int i=0;i<n && curh<=k;i++)
    {
        int curv=q[i].second.first;
        double curl = curh * h;
        double curt = curl / curv;
        if (curt<=t+eps)
        {
            printf("%d ",q[i].second.second);
            curh++;
        }
    }



    return 0;
}