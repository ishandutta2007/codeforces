#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,m,k;

int inp[nmax];

int pref[nmax][nmax];

void add_rect(int x1,int y1,int x2,int y2,int add)
{
    x1=max(1,x1);
    x2=min(n-k+1,x2);
    y1=max(1,y1);
    y2=min(n-k+1,y2);

    if(x1>x2||y1>y2)return;

    //cout<<"add_rect "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" with "<<add<<endl;

    pref[x1][y1]+=add;
    pref[x2+1][y1]-=add;
    pref[x1][y2+1]-=add;
    pref[x2+1][y2+1]+=add;

}

int common(int a,int b,int u,int v)
{
    int ret=min(b,v)-max(a,u)+1;
    ret=max(ret,0);
    return ret;
}
void push(int l,int r)
{
    int lq=1,rq=n-k+1;

    while(lq<=rq)
    {
        int coeff;
        int LHS=common(lq,lq+k-1,l,r);
        int RHS=common(rq,rq+k-1,l,r);

        int me;

        if(LHS<RHS)
        {
            me=lq;
            coeff=LHS;
            lq++;
        }
        else
        {
            me=rq;
            coeff=RHS;
            rq--;
        }

        add_rect(1,me,lq-1,me,coeff);
        add_rect(me,rq+1,me,n-k+1,coeff);
    }
}
int main()
{
    scanf("%i%i%i",&n,&m,&k);

    for(int i=1;i<=m;i++)
    {
        int l,r;

        scanf("%i%i",&l,&r);

        push(l,r);
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pref[i][j]+=pref[i-1][j];

    int ret=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            pref[i][j]+=pref[i][j-1];
            ret=max(ret,pref[i][j]);

            //cout<<i<<" "<<j<<" -> "<<pref[i][j]<<endl;
        }

    printf("%i\n",ret);

    return 0;
}