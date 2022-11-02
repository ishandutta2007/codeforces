#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, a, b, A[100010], chk[100010][5];
char S[100010], X[5]={'A', 'A', 'N', 'O', 'T'};
main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%s", &S);
        n=strlen(S);
        int cnt[5]={};
        for(i=0;i++<n;)
        {
            char c=S[i-1];
            if(c=='A')A[i]=1;
            if(c=='N')A[i]=2;
            if(c=='O')A[i]=3;
            if(c=='T')A[i]=4;
            cnt[A[i]]++;
        }
        vector<int>v;
        for(i=0;i++<4;)v.push_back(i);
        for(j=0;j++<4;)
        {
            for(i=0;i++<n;)
            {
                if(A[i]==j)chk[i][j]=chk[i-1][j]+1;
                else chk[i][j]=chk[i-1][j];
            }
        }
        int ans=-1;vector<int>ans2;
        do
        {
            int z=0;
            for(j=0;j<v.size()-1;j++)
            {
                for(i=0;i++<n;)
                {
                    if(A[i]!=v[j])continue;
                    int x=0;
                    for(k=j+1;k<v.size();k++)
                    {
                        x+=chk[i][v[k]];
                    }
                    z+=x;
                }
            }
            if(ans<z)
            {
                ans=z;
                ans2=v;
            }
        }while(next_permutation(v.begin(), v.end()));
        for(i=0;i<ans2.size();i++)
        {
            for(j=0;j<cnt[ans2[i]];j++)printf("%c", X[ans2[i]]);
        }puts("");
    }
}