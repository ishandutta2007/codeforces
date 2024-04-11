#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, s, e, A[300010], B[300010];
vector<int>v[300010];
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        for(i=0;i++<n;)scanf("%d", &A[i]),B[i]=0,v[i].clear();
        for(i=0;i++<n;)
        {
            v[A[i]].push_back(i);
        }
        s=1;
        e=n;
        for(i=0;i++<n-1;)
        {
            if(v[i].size()==0)
            {
                break;
            }
            if(v[i].size()>=2)
            {
                B[i]=1;
                break;
            }
            if(v[i][0]==s)
            {
                B[i]=1;
                s++;
            }
            else if(v[i][0]==e)
            {
                B[i]=1;
                e--;
            }
            else
            {
                B[i]=1;
                break;
            }
        }
        B[n]=1;
        for(i=0;i++<n;)
        {
            if(v[i].size()==0)
            {
                B[n]=0;
            }
        }
        for(i=n;i>0;i--)printf("%d", B[i]);
        puts("");
    }
}