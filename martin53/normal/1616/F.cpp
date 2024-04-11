#include<bits/stdc++.h>
using namespace std;

const int nmax=65,mmax=257;

int n,m;

int id[nmax][nmax];

struct line
{
    short coeff[mmax];
    short result;
};

int pointer=0;

line all[nmax*nmax*nmax+mmax];

void add_equation(vector<int> on,int result)
{
    //cout<<"add_equation "<<result<<" : ";for(auto w:on)cout<<w<<" ";cout<<endl;

    pointer++;

    all[pointer].result=result;
    for(auto w:on)
        all[pointer].coeff[w]=1;
}

int equation_for_id[mmax];
int outp[mmax];

int eval(int cur)
{
    return (cur%3+3)%3;
}

void solve()
{
    memset(equation_for_id,0,sizeof(equation_for_id));

    for(int j=1;j<=pointer;j++)
    {
        all[j].result=0;
        for(int p=1;p<mmax;p++)
            all[j].coeff[p]=0;
    }

    pointer=0;

    scanf("%i%i",&n,&m);

    memset(id,-1,sizeof(id));

    for(int i=1;i<=m;i++)
    {
        int a,b,c;

        scanf("%i%i%i",&a,&b,&c);

        if(a>b)swap(a,b);

        if(c!=-1)add_equation({i},c);

        id[a][b]=i;
    }

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                if(id[i][j]!=-1&&id[i][k]!=-1&&id[j][k]!=-1)
                    add_equation({id[i][j],id[j][k],id[i][k]},0);

    /*
    cout<<"equations: "<<endl;
    for(int i=1;i<=pointer;i++)
    {
        cout<<all[i].result<<" : ";for(int j=1;j<=m;j++)cout<<all[i].coeff[j]<<" ";cout<<endl;
    }
    */

    int start=1;

    for(int i=1;i<=m;i++)
    {
        bool ok=0;

        for(int j=start;j<=pointer;j++)
            if(all[j].coeff[i])
            {
                ok=1;
                swap(all[j],all[start]);
                break;
            }

        if(ok==0)continue;

        equation_for_id[i]=start;

        for(int j=start+1;j<=pointer;j++)
            if(all[j].coeff[i])
            {
                int mult=1+(all[start].coeff[i]!=all[j].coeff[i]);

                for(int p=i;p<=m;p++)
                    all[j].coeff[p]=eval(all[j].coeff[p]-mult*all[start].coeff[p]);

                all[j].result=eval(all[j].result-mult*all[start].result);
            }

        start++;
    }

    /*
    cout<<"equations: "<<endl;
    for(int i=1;i<=pointer;i++)
    {
        cout<<all[i].result<<" : ";for(int j=1;j<=m;j++)cout<<all[i].coeff[j]<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=pointer;i++)
        if(all[i].result)
        {
            bool all_zero=1;

            for(int j=1;j<=m;j++)
                if(all[i].coeff[j])all_zero=0;

            if(all_zero)
            {
                printf("-1\n");
                return;
            }
        }

    for(int i=m;i>=1;i--)
        if(equation_for_id[i]==0)outp[i]=3;
        else
        {
            int where=equation_for_id[i];

            outp[i]=all[where].result;

            for(int j=i+1;j<=m;j++)
                outp[i]=eval(outp[i]-outp[j]*all[where].coeff[j]);

            if(all[where].coeff[i]==2)outp[i]=eval(outp[i]*2);

            if(outp[i]==0)outp[i]=3;
        }

    for(int i=1;i<=m;i++)
        printf("%i ",outp[i]);
    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}