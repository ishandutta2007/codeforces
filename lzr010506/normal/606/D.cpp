#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 1061109567;  
int n,m;  
struct A  
{  
    int v;  
    int u;  
    int o;  
    bool operator < (const A& b)const  
    {  
        if(v != b.v)return v < b.v;  
        return u > b.u;  
    }  
}a[N];  
int b[N],c[N];  
bool check()  
{  
    int ed = 1;  
    int x = 1;   
    int y = 3;  
    for(int i = 1; i <= m; i ++)  
    {  
        if(a[i].u == 1)  
        {  
            b[a[i].o] = ed;  
            c[a[i].o] = ++ ed;  
        }  
        else  
        {  
            if(y > ed)return 0;  
            b[a[i].o] = x;  
            c[a[i].o] = y;  
            if(-- x == 0)  
            {  
                ++ y;  
                x = y - 2;  
            }  
        }  
    }  
    return 1;  
}  
int main()  
{  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(int i = 1; i <= m; i ++)
		scanf("%d%d",&a[i].v,&a[i].u), a[i].o = i;  
        sort(a + 1, a + m + 1);  
        if(check())  
        {  
            for(int i = 1; i <= m; i ++)printf("%d %d\n",b[i],c[i]);  
        }  
        else puts("-1");  
    }  
    return 0;  
}