#include<bits/stdc++.h>
using namespace std;
int n,i,check,f,check1,check2,s,p,j,h;
long long checki=1073741823;
int d[35];
int pow(int j)
{
    p=1;
    for(s=1;s<=j-1;s++)
    {
        p*=2;
    }
    return p;
}
int main(){
    cout<<"? 0 0\n"<<flush;
    cin>>f;
    h=f;
    for(i=1;i<=31;i++)
    {
        d[i]=pow(i);
    }
    for(i=30;i>=2;i--)
    {
        if(h==-1)
        {
            check2+=d[i];
            printf("? %d %d\n",check1,check2);
            fflush(stdout);
            cin>>f;
            if(f==-1)
            {
                check1+=d[i]-1;
                check2+=d[i]-1;
                printf("? %d %d\n",check1,check2);
                fflush(stdout);
                cin>>f;
                if(f==-1)
                {
                    check2-=2*d[i]-1;
                    check1-=d[i]-1;
                    h=-1;
                }
                else if(f==1)
                {
                    h=-1;
                    check2-=d[i]-1;
                    check1-=d[i]-1;
                }
                else
                {
                    check2-=d[i]-1;
                    check1-=d[i]-1;
                    h=0;
                }
            }
            else if(f==1)
            {
                check1+=d[i];
                printf("? %d %d\n",check1,check2);
                fflush(stdout);
                cin>>f;
                if(f==1)
                {
                    check1-=d[i];
                    h=1;
                }
            }
            else if(f==0)
            {
                h=0;
            }
        }
        else if(h==1)
        {
            check1+=d[i];
            printf("? %d %d\n",check1,check2);
            fflush(stdout);
            cin>>f;
            if(f==1)
            {
                check1+=d[i]-1;
                check2+=d[i]-1;
                printf("? %d %d\n",check1,check2);
                fflush(stdout);
                cin>>f;
                if(f==1)
                {
                    check1-=2*d[i]-1;
                    check2-=d[i]-1;
                    h=1;
                }
                else if(f==-1)
                {
                    h=1;
                    check1-=d[i]-1;
                    check2-=d[i]-1;
                }
                else
                {
                    check1-=d[i]-1;
                    check2-=d[i]-1;
                    h=0;
                }
            }
            else if(f==-1)
            {
                check2+=d[i];
                printf("? %d %d\n",check1,check2);
                fflush(stdout);
                cin>>f;
                if(f==-1)
                {
                    check2-=d[i];
                    h=-1;
                }
            }
            else if(f==0)
            {
                h=0;
            }
        }
        else if(h==0)
        {
            check1+=d[i];
            printf("? %d %d\n",check1,check2);
            fflush(stdout);
            cin>>f;
            if(f==1)
            {
                check1-=d[i];
            }
            else if(f==-1)
            {
                check2+=d[i];
            }
        }
    }
    if(h==0)
    {
        check1+=1;
        printf("? %d %d\n",check1,check2);
        fflush(stdout);
        cin>>f;
        if(f==1)
        {
            check1-=1;
        }
        else
        {
            check2+=1;
        }
    }
    else if(h==1)
    {
        check1+=1;
    }
    else
    {
        check2+=1;
    }
    printf("! %d %d\n",check1,check2);
    fflush(stdout);
    return 0;
}