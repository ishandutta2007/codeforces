#include <bits/stdc++.h>

using namespace std;
int st[300005];
bool cmp (int a, int b)
{
    return a>b;
}
char v[10];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j,k=0,cur=0,cnt=0;
    cin>>n;
    for(i=1;i<=2*n;++i)
    {
        int a;
        cin>>v;
        if(v[0]=='a')
        {
            cin>>a;
            st[++k]=a;
        }
        else
        {
            ++cur;
            if(st[k]!=cur && k>=1)
            {
                ++cnt;
                k=0;
            }
            if(k)
                --k;
        }
    }
    cout<<cnt;
    return 0;
}