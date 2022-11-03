#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;
const int N=2005;
int n,m;
char s[N];
bitset<N> b[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++)
            if(s[j]=='1') b[i].set(j);
        //cout<<b[i].to_string()<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        bitset<N> t;t.reset();
        for(int j=1;j<=n;j++)
            if(j!=i) t|=b[j];
        //cout<<t.to_string()<<endl;
        if(t.count()==m){printf("YES");return 0;}
    }
    printf("NO");
    return 0;
}