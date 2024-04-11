#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
queue<pii> q[2];
inline void print(int k,int c)
{
    printf("%d %d %d\n",c,q[k].front().first,q[k].front().second);
    fflush(stdout),q[k].pop();
}
int main()
{
    int n,i,j,x,_;
    scanf("%d",&n),_=n*n;
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            q[(i+j)&1].push(make_pair(i,j));
    while(_--)
    {
        scanf("%d",&x);
        if(x==1)
            if(q[1].empty()) print(0,3);
            else print(1,2);
        else if(x==2)
            if(q[0].empty()) print(1,3);
            else print(0,1);
        else if(q[0].empty()) print(1,2);
        else print(0,1);
    }
    return 0;
}