#include<bits/stdc++.h>
using namespace std;

const int nmax=5e4+42;

struct point
{
    int x,y,z,id;
};
int n;
point inp[nmax];

bool cmp(point a,point b)
{
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}

point help[nmax];
int pointer=0;

void compress_z()
{
    pointer=0;
    for(int i=1;i<=n;i++)
        if(pointer&&help[pointer].x==inp[i].x&&help[pointer].y==inp[i].y)
        {
            printf("%i %i\n",help[pointer].id,inp[i].id);
            pointer--;
        }
        else
        {
            pointer++;
            help[pointer]=inp[i];
        }

    //cout<<"pointer= "<<pointer<<endl;

    n=pointer;
    for(int i=1;i<=n;i++)
        inp[i]=help[i];
}

void compress_y()
{
    pointer=0;
    for(int i=1;i<=n;i++)
        if(pointer&&help[pointer].x==inp[i].x)
        {
            printf("%i %i\n",help[pointer].id,inp[i].id);
            pointer--;
        }
        else
        {
            pointer++;
            help[pointer]=inp[i];
        }
    //cout<<"pointer= "<<pointer<<endl;

    n=pointer;
    for(int i=1;i<=n;i++)
        inp[i]=help[i];
}

void compress_x()
{
    //cout<<"n= "<<n<<endl;

    for(int i=1;i<n;i=i+2)
        printf("%i %i\n",inp[i+1].id,inp[i].id);
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i%i%i",&inp[i].x,&inp[i].y,&inp[i].z);
        inp[i].id=i;
    }

    sort(inp+1,inp+n+1,cmp);

    compress_z();
    compress_y();
    compress_x();

    return 0;
}