#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int n,m,p,maxi;
char c[20][20];
bool q[20][20],t[20],tbest[20];
void func()
{
    //cout<<p<<endl;
    if (p<n)
    {
        p++;
        func();
        p--;
        t[p]=true;
        p++;
        func();
        p--;
        t[p]=false;
    }
    else
    {
        /*cout<<n;
        for (int i=0;i<n && cout<<endl;i++)
            for (int j=0;j<n && cout<<" ";j++)
                if (q[i][j]) cout<<"1"; else cout<<"0";*/
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (t[i] && t[j] && (q[i][j] || q[j][i])) return;
    
                //for (int i=0;i<n;i++) cout<<t[i]<<" ";
        //cout<<endl;
        //cout<<"!";
        int cur=0;
        for (int i=0;i<n;i++) if (t[i]) 
        {
            //cout<<i<<endl;
            cur++;
        }
        //cout<<endl;
        if (cur>maxi) 
        {
            for (int i=0;i<n;i++) tbest[i]=t[i];
            maxi=cur;
        }
    }
}
int main(){
   // freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++)
        cin.getline(c[i],15);
    for (int i=0;i<m;i++)
    {
        //cout<<i<<endl;
        int h=0,nfir=-1,nsec=-1;
        char ch[35],a[20],b[20];
        cin.getline(ch,35);
        while (ch[h]!=' ') 
        {
            a[h]=ch[h];
            h++;
        }
        a[h]=0;
        h++;
        int g=0;
        while (ch[h]!=0) 
        {
            b[g]=ch[h];
            h++;
            g++;
        }
        b[g]=0;
        for (int j=0;j<n;j++)
        {
            
            int hh=0;
            bool bo=false;
            while (a[hh]==c[j][hh] && !bo) 
            {
                if (a[hh]==0) bo=true;
                hh++;
            }
            if (bo) nfir=j;
            hh=0;
            bo=false;
            while (b[hh]==c[j][hh] && !bo) 
            {
                if (b[hh]==0) bo=true;
                hh++;
            }
            if (bo) nsec=j;
            //cout<<"1"<<endl;
        }
        //cout<<"!"<<endl;
        //cout<<nfir<<" "<<nsec<<endl;
        q[nfir][nsec]=true;
        q[nsec][nfir]=true;
    }
    //cout<<"!"<<endl;
    func();
    cout<<maxi<<endl;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (tbest[i] && tbest[j])
            {
                int hh=0;
                while (c[i][hh]==c[j][hh]) hh++;
                if (int(c[i][hh])>int(c[j][hh]))
                {
                    hh=0;
                    bool b1=true;
                    bool b2=true;
                    while (b1 || b2)
                    {
                        if (!c[i][hh]) b1=false;
                        if (!c[j][hh]) b2=false;
                        char x=c[i][hh];
                        c[i][hh]=c[j][hh];
                        c[j][hh]=x;
                        hh++;
                    }
                }
            }
    for (int i=0;i<n;i++)
    {
        if (tbest[i]) 
        {
            int hh=0;
            while (c[i][hh]) cout<<c[i][hh++];
            cout<<endl;
        }
    }
    return 0;
}