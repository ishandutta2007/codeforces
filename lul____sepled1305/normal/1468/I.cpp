#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;

int GCD(int a,int b)
{
    if(a > b)
        swap(a,b);
    if(a == 0)
        return b;
    if(b%a == 0)
        return a;
    return GCD(b%a,a);
}

struct vect
{
    int x,y,scale;

    vect(int a,int b)
    {
        int curx = a, cury = b;
        x = a/GCD(abs(curx),abs(cury));
        y = b/GCD(abs(curx),abs(cury));
        scale = GCD(abs(curx),abs(cury));
    }
};

void swap(vect &a, vect &b)
{
    vect c = b;
    b = a;
    a = c;
}

long long area(vect a, vect b)
{
    long long sc = 1LL*a.scale*b.scale;
    long long base = (a.x+b.x)*(a.y+b.y)-(a.x*a.y)-(b.x*b.y)-2*(a.x*b.y);
    return sc*base;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,dx1,dx2,dy1,dy2;
    cin>>n>>dx1>>dy1>>dx2>>dy2;
    if((dx1 == 0 && dy1 == 0) || (dx2 == 0 && dy2 == 0))
    {
        cout<<"NO\n";
    }
    else
    {
        if(dy1 < 0)
            dy1 = -dy1, dx1 = -dx1;
        if(dy2 < 0)
            dy2 = -dy2, dx2 = -dx2;
        vect a = vect(dx1,dy1);
        vect b = vect(dx2,dy2);
        if(abs(area(a,b)) != n)
            cout<<"NO";
        else
        {
            cout<<"YES\n";
            if(area(a,b)<0)
                swap(a,b);

            int gc = GCD(abs(a.x*a.scale),abs(b.x*b.scale));
            int i,j;
            for(i=0; i<gc; i++)
            {
                for(j=0; j<area(a,b)/gc; j++)
                    cout<<i<<' '<<j<<endl;
            }
        }
    }
}