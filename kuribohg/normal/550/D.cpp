#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
struct Node
{
    int d,id;
    friend bool operator<(const Node &p,const Node &q)
    {
        return p.d>q.d;
    }
}A[MAXN];
int n,K,M;
inline void adde(int f,int t)
{
    printf("%d %d\n",f,t);
    printf("%d %d\n",K+f,K+t);
}
int main()
{
    scanf("%d",&n);
    if(n%2==0) {puts("NO");return 0;}
    if(n==1)
    {
        puts("YES");
        puts("2 1");
        puts("1 2");
        return 0;
    }
    puts("YES");
    K=n+2;
    for(int i=1;i<K;i++) A[i].d=n,A[i].id=i;
    A[K].d=n-1,A[K].id=K;
    M=n*K;
    printf("%d %d\n",K+K,M);
    printf("%d %d\n",K,K+K);
    for(int i=1;i<=K;i++)
    {
        sort(A+i,A+K+1);
        int x=A[i].d;
        for(int j=i+1;j<=i+x;j++)
            adde(A[i].id,A[j].id),A[j].d--;
    }
    return 0;
}