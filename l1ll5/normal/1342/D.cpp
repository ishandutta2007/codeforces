#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k;
int m[N];
int c[N];
int nxt[N];
struct zgz
{
    int a;
    friend bool operator < (const zgz &A,const zgz &B)
    {
        return A.a>B.a;
    }
};
multiset<zgz> S;
vector<int> ans[N];
int Ans;
int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++) m[i]=read(),S.insert((zgz){m[i]});
//    cerr<<(*(S.begin())).a<<endl;
    //return 0;


    int lst=0;
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        if(c[i]!=c[i-1])
        {
            lst=i-1;
        }
        nxt[i]=lst;
    }

    int curr=0;
    for(int i=1;i<=n;i++) curr+=m[i];

    /*for(int i=1;i<=k;i++)
    cout<<nxt[i]<<' ';
    cout<<endl;*/



    while(!S.empty())
    {
        Ans++;
        auto it=S.begin();
        int x=it->a;
        int lim=c[x];
        int tot=0;

        while(x)
        {
        //    cerr<<x<<endl;
            bool flag=0;
            while(tot<lim)
            {
                it=S.lower_bound((zgz){x});
                if(it==S.end()) flag=1;

                if(flag) break ;

                int ret=(*it).a;
                ans[Ans].push_back(ret); tot++;
                it=S.lower_bound((zgz){ret});
                S.erase(it);
                if(S.empty()) break ;
            }
            if(flag) break ;
            if(!flag)
            {
                it=S.begin();
                int hh=it->a;
                if(tot==lim)
                {
                    x=min(nxt[x],hh);
                    lim=max(lim,c[x]);
                }
                else
                {
                    x=min(x-1,hh);
                    lim=max(lim,c[x]);
                }
            }
        }
    }
    for(int i=1;i<=Ans;i++) reverse(ans[i].begin(),ans[i].end());
    printf("%d\n",Ans);
    for(int i=1;i<=Ans;i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size()-1;j++)
        printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][ans[i].size()-1]);
    }
}