#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,m;
pair<int/*value*/,int/*index*/> computer[nmax],socket[nmax];
int comp=0,total=0;
int sock[nmax];
int use[nmax];
void reduce(int step)
{
    int n_=0,m_=0,i=1,j=1;

    while(i<=n&&j<=m)
    {
        if(computer[i].first==socket[j].first)
        {
            //cout<<i<<" "<<j<<" "<<computer[i].first<<" "<<computer[i].second<<" "<<socket[j].first<<" "<<socket[j].second<<endl;
            comp++;
            total=total+step;
            sock[socket[j].second]=step;
            use[computer[i].second]=socket[j].second;
            i++;
            j++;
        }
        else if(computer[i].first<socket[j].first)
        {
            n_++;
            computer[n_]=computer[i];
            i++;
        }
        else
        {
            m_++;
            socket[m_]=socket[j];
            j++;
        }
    }


    while(i<=n)
    {
            n_++;
            computer[n_]=computer[i];
            i++;
    }

    while(j<=m)
    {

            m_++;
            socket[m_]=socket[j];
            j++;
    }

    n=n_;
    m=m_;
}
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++){scanf("%i",&computer[i].first);computer[i].second=i;}
for(int i=1;i<=m;i++){scanf("%i",&socket[i].first);socket[i].second=i;}

int n_=n,m_=m;
sort(computer+1,computer+n+1);
sort(socket+1,socket+m+1);

reduce(0);

for(int step=1;step<=30;step++)
{
    for(int i=1;i<=m;i++)
        if(socket[i].first%2==0)socket[i].first=socket[i].first/2;
        else socket[i].first=socket[i].first/2+1;
    reduce(step);
}

cout<<comp<<" "<<total<<endl;
for(int i=1;i<=m_;i++)printf("%i ",sock[i]);printf("\n");
for(int i=1;i<=n_;i++)printf("%i ",use[i]);printf("\n");
return 0;
}