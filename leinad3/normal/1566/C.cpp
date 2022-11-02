#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, s;
char A[100010], B[100010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        scanf("%s %s", &A, &B);
        int ans=0;
        vector<int>v;
        v.push_back(-1);
        for(i=0;i<n;i++)
        {
            if(A[i]!=B[i])
            {
                ans+=2;
                v.push_back(i);
            }
        }
        v.push_back(n);
        for(i=0;i+1<v.size();i++)
        {
            a=v[i]+1, b=v[i+1]-1;
            for(j=a;j<b;j++)
            {
                if(A[j]!=A[j+1])ans++,j++;
            }
            for(j=a;j<=b;j++)if(A[j]=='0')ans++;
        }
        printf("%d\n", ans);
    }
}