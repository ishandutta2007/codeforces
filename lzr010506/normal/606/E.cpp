#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;  
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7;  
struct point
{  
    int x,y;  
    point(){}  
    point(int x_,int y_){x = x_; y = y_;}  
    bool operator < (const point& b)const  
    {  
        return x != b.x? x < b.x: y < b.y;  
    }  
    point operator - (const point& b)const  
    {  
        return point(x - b.x, y - b.y);  
    }  
    LL operator * (const point& b)const  
    {  
        return (LL)x * b.y - (LL)y * b.x;  
    }  
}a[N];  
int s[N];  
int n;  
double X,Y;

template <class T1,class T2>inline void gmin(T1 &a,T2 b){if(b<a)a=b;}  
int main()  
{  
    scanf("%d",&n);  
    scanf("%lf%lf",&X,&Y);  
    for(int i = 1; i <= n; i ++)
		scanf("%d%d",&a[i].x,&a[i].y);  
    sort(a + 1, a + n + 1);
    int top = 0;  
    for(int i = 1; i <= n; i ++)  
    {
        while(top && a[i].y >= a[s[top]].y) top --; 
        while(top >= 2 && (a[i] - a[s[top - 1]]) * (a[s[top]] - a[s[top - 1]]) <= 0) top --;  
        s[++ top] = i;  
    }  
    double ans = max(X / a[s[1]].x, Y / a[s[1]].y);  
    for(int i = 1; i < top; i ++)  
    {  
        point p1=a[s[i]];  
        point p2=a[s[i + 1]];  
        double l = 0;  
        double r = 1;  
        double tmpl;  
        double tmpr;  
        for(int tim = 1; tim <= 200; tim ++)  
        {  
            double lm = (l + l + r) / 3;  
            double rm = (l + r + r) / 3;  
            tmpl=max( X / (lm * p1.x + (1 - lm) * p2.x), Y / (lm * p1.y + (1 - lm) * p2.y) );  
            tmpr=max( X / (rm * p1.x + (1 - rm) * p2.x), Y / (rm * p1.y + (1 - rm) * p2.y) );  
            tmpl < tmpr? r = rm: l = lm;  
        }  
        gmin(ans,tmpl);  
    }  
    printf("%.15f\n",ans);  
    return 0;  
}