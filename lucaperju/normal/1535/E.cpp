#include <bits/stdc++.h>

using namespace std;

int a[300003],c[300003];
int p[300003][20];
long long cnt,cst;
void query (int nod, int &w)
{
    for(int i=18;i>=0;--i)
        if(a[p[nod][i]])
            nod=p[nod][i];
    int cat=min(w,a[nod]);
    cst+=c[nod]*1LL*cat;
    a[nod]-=cat;
    w-=cat;
    cnt+=cat;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,q,i,j,t;
    cin>>q>>a[0]>>c[0];
    for(i=1;i<=q;++i)
    {
        int f;
        cin>>f;
        if(f==2)
        {
            int w,nod;
            cin>>nod>>w;
            cnt=cst=0;
            while(w && a[nod])
                query(nod,w);
            cout<<cnt<<' '<<cst<<'\n';
        }
        if(f==1)
        {
            cin>>p[i][0]>>a[i]>>c[i];
            for(j=1;j<=18;++j)
                p[i][j]=p[p[i][j-1]][j-1];
        }
    }
    return 0;
}