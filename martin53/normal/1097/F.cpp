#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,MX=7000+42;

bitset<MX> on[nmax]/*parity of x: i|x*/,idle,mem_coeff[MX],mobius_coeff[MX];

int n,q;

int mobius[MX];

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<MX;i++)
    {
        for(int j=1;j<=i;j++)
            if(i%j==0)mem_coeff[i][j]=1;
    }

    for(int i=1;i<MX;i++)
    {
        int deg=0,square=0;

        int mem_i=i;

        for(int j=2;j*j<=mem_i;j++)
            if(mem_i%j==0)
            {
                if(mem_i%(j*j)==0)square=1;

                if(mem_i%j==0)deg++;
            }

        if(mem_i!=1)deg++;

        if(square==0)
        {
            if(deg%2==1)mobius[i]=1;
            else mobius[i]=-1;
        }
    }

    for(int i=1;i<MX;i++)
    {
        for(int j=i;j<MX;j=j+i)
            if(mobius[j/i])mobius_coeff[i][j]=1;
    }

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==1)
        {
            int pos,new_val;
            scanf("%i%i",&pos,&new_val);

            on[pos]=mem_coeff[new_val];
        }

        if(type==2)
        {
            int pos,pos_y,pos_z;

            scanf("%i%i%i",&pos,&pos_y,&pos_z);

            on[pos]=on[pos_y]^on[pos_z];
        }

        if(type==3)
        {
            int pos,pos_y,pos_z;

            scanf("%i%i%i",&pos,&pos_y,&pos_z);

            on[pos]=on[pos_y]&on[pos_z];
        }

        if(type==4)
        {
            int pos,val;
            scanf("%i%i",&pos,&val);

            int ret=(on[pos]&mobius_coeff[val]).count();

            printf("%i",ret%2);
        }
    }
    return 0;
}