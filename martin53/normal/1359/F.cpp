#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int nmax=25000+42;
const double eps=1/1e9;

int n;
struct info
{
    int x,y,dx,dy;
    double s;
};
info inp[nmax];

bool solved=0;
double outp=1e18;

void update(double val)
{
    //cout<<"update "<<val<<endl;

    outp=min(outp,val);
    solved=1;
}

void read()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i%i%i%i%lf",&inp[i].x,&inp[i].y,&inp[i].dx,&inp[i].dy,&inp[i].s);
        inp[i].s=1.0*inp[i].s/sqrt(inp[i].dx*inp[i].dx+inp[i].dy*inp[i].dy);
        //cout<<"s= "<<inp[i].s<<endl;
    }
}

mt19937 rng(42);
void gen()
{
    int MX=1e3;

    n=2.5e4;
    for(int i=1;i<=n;i++)
    {
        inp[i].x=rng()%MX;
        inp[i].y=rng()%MX;
        inp[i].dx=rng()%MX;
        inp[i].dy=rng()%MX;
        inp[i].s=rng()%MX;

        inp[i].s=1.0*inp[i].s/sqrt(inp[i].dx*inp[i].dx+inp[i].dy*inp[i].dy);
    }
}

int main()
{
    read();
    //gen();

    double a,b,c,d;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                //cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                /*
                t=a+b*w=c+d*w
                min(max(t,w)), t,w>=0
                */

                if(/*abs(b-d)>eps*/inp[j].dx*inp[i].dy!=inp[i].dx*inp[j].dy)
                {
                    a=(inp[j].x-inp[i].x)/(inp[i].dx*inp[i].s);
                    b=(inp[j].dx*inp[j].s)/(inp[i].dx*inp[i].s);

                    //c=(inp[j].y-inp[i].y)/(inp[i].dy*inp[i].s);
                    //d=(inp[j].dy*inp[j].s)/(inp[i].dy*inp[i].s);

                    //double w=(c-a)/(b-d);
                    double w=((inp[j].y-inp[i].y)*inp[i].dx-(inp[j].x-inp[i].x)*inp[i].dy)/(inp[j].dx*inp[j].s*inp[i].dy-inp[j].dy*inp[j].s*inp[i].dx);

                    double t=a+b*w;

                    //cout<<"w= "<<w<<" t= "<<t<<" "<<a+b*w<<" "<<c+d*w<<endl;

                    if(w>=0&&t>=0)update(max(t,w));
                }
                else//b=d
                {
                    a=(inp[j].x-inp[i].x)/(inp[i].dx*inp[i].s);
                    b=(inp[j].dx*inp[j].s)/(inp[i].dx*inp[i].s);

                    c=(inp[j].y-inp[i].y)/(inp[i].dy*inp[i].s);

                    if(abs(a-c)>eps)continue;
                    else//a=c
                    {
                        if(a>=0&&b>=0)update(a);
                        else if(a<=0&&b<=0)continue;
                        else if(a>=0)update(a/(1-b));
                        else update(-a/b);
                    }
                }
            }

    if(solved)printf("%.9f\n",outp);
    else printf("No show :(\n");
    return 0;
}