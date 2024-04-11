#include <bits/stdc++.h>
#define N 100
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
vector<int> a;
bool ok(){
    for(int i=0;i<n;i++)
    if(a[i]!=(i+1)) return 0;
    return 1;
}
vector<int> tmp[80],tt;
void doit(vector<int> d){
    int p=0;
    for(int i=0;i<d.size();i++){
        int t=d[i];
        tmp[i].clear();
        for(int j=1;j<=t;j++) tmp[i].push_back(a[p]),p++;
    }
    a.clear();
    for(int i=d.size()-1;i>=0;i--){
        for(int j=0;j<tmp[i].size();j++) a.push_back(tmp[i][j]);
    }
}
int find(int x){
    for(int i=0;i<n;i++)
    if(a[i]==x) return i;
}
bool ok2(){
    for(int i=0;i<n;i++)
    if(a[i]!=(n-i)) return 0;
    return 1;
}
int q;
vector<int> ans[N];
int p[1000];
int main()
{
    srand(time(0));
    n=read();
    if(n==1){
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++) a.push_back(read());
/*    n=52;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++) swap(p[i],p[rand()%n+1]);

    for(int i=1;i<=n;i++) a.push_back(p[i]);*/

    int L,R,ed=0;
    bool inc=1;

    while(!ok() && !ok2()){

    /*    cout<<"hh"<<endl;
        for(int i=0;i<n;i++) cout<<a[i]<<' ';
        cout<<endl;*/
        int v;
        if(inc){
            L=find(1);
            R=L;
            while(R+1<n && a[R+1]==a[R]+1 ) R++;
            v=find(a[R]+1);
        } else {
            R=find(1);
            L=R;
            while(L && a[L-1]==a[L]+1){
                L--;
            }
            v=find(a[L]+1);
        }


        tt.clear();
    //    cerr<<v<<' '<<L<<' '<<R<<' '<<inc<<' '<<a[R]<<endl;

        if(v>R){
            if(inc){
                if(L) tt.push_back(L);
                for(int i=1;i<=R-L+1;i++) tt.push_back(1);
                if(v-R)
                tt.push_back(v-R);
                if(n-1-v)
                tt.push_back(n-1-v);
                inc ^= 1;
            } else {
                if(L) tt.push_back(L);
                if(R-L+1)
                tt.push_back(R-L+1);
                if(v-R)
                tt.push_back(v-R);
                if(n-1-v)
                tt.push_back(n-1-v);
            }

        } else {
            if(inc){
        //        cerr<<"a"<<endl;
                if(v)
                tt.push_back(v);
                if(L-v)
                tt.push_back(L-v);
                if(R-L+1)
                tt.push_back(R-L+1);
                if(n-1-R)
                tt.push_back(n-1-R);
            } else {
                if(v)
                tt.push_back(v);
                if(L-v)
                tt.push_back(L-v);
                for(int i=1;i<=R-L+1;i++) tt.push_back(1);
                if(n-1-R)
                tt.push_back(n-1-R);
                inc ^= 1;
            }
        }



        q++;

        /*cout<<tt.size()<<' ';
        for(int i=0;i<tt.size();i++) cout<<tt[i]<<' ';
        cout<<endl;*/
        for(int i=0;i<tt.size();i++) ans[q].push_back(tt[i]);
        //cout<<tt[i]<<' ';
        //cout<<endl;
        doit(tt);
    }

    if(ok2()){
        q++;
        tt.clear();
        for(int i=1;i<=n;i++) tt.push_back(1);
        for(int i=0;i<tt.size();i++) ans[q].push_back(tt[i]);
    }

    cout<<q<<endl;
    for(int i=1;i<=q;i++){
        cout<<ans[i].size()<<' ';
        for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}