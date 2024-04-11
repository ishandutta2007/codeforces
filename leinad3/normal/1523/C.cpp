#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        vector<int>V;
        for(i=0;i++<n;)
        {
            scanf("%d", &a);
            if(a==1)
            {
                V.push_back(1);
            }
            else
            {
                while(V.back()!=a-1)V.pop_back();
                V.back()=a;
            }
            for(j=0;j<V.size();j++)
            {
                if(j+1!=V.size())printf("%d.", V[j]);
                else printf("%d\n", V[j]);
            }
        }
    }
}