#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[100010];
int ask(int a)
{
    printf("? %d\n", a);fflush(stdout);
    int x;scanf("%d", &x);
    return x;
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        set<int>s;
        for(i=0;i++<n;)s.insert(i);
        for(i=0;i++<n;)A[i]=0;
        a=1;b=1;
        ask(a);
        while(1)
        {
            if(s.size()==1)
            {
                a=*s.begin();
                A[a]=a;
                break;
            }
            vector<int>v;
            while(1)
            {
                int x=ask(a);
                bool flag=false;
                if(s.find(x)==s.end())flag=true;
                else s.erase(x);
                v.push_back(x);
                if(flag)break;
            }
            for(int i=0;i<v.size()-1;i++)A[v[i]]=v[i+1];
            if(s.size()==0)break;
            a=*s.begin();
        }
        printf("! ");
        for(i=0;i++<n;)printf("%d ", A[i]);puts("");fflush(stdout);
    }
}