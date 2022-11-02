#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define rvc(i,S) for(int i=0;i<S.size();++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n;
int a[N];
vector<int> v;
int main()
{
    t=read();
    while(t--){
        v.clear();
        v.push_back(0);
        n=read();
        int tot=0;
        for(int i=1;i<=n;i++) a[i]=read(),tot+=a[i];

    /*    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<endl;*/

        if(tot==0){
            puts("NO");
            continue ;
        }
        if(tot<0){
            for(int i=1;i<=n;i++){
                if(a[i]<0) v.push_back(a[i]);
            }
        /*    for(int i=1;i<=n;i++)
            cout<<v[i]<<' ';
            cout<<endl;*/
            for(int i=1;i<=n;i++){
                if(a[i]>0) v.push_back(a[i]);
            }

            for(int i=1;i<=n;i++){
                if(a[i]==0) v.push_back(a[i]);
            }
        } else {
            for(int i=1;i<=n;i++){
                if(a[i]>0) v.push_back(a[i]);
            }

            for(int i=1;i<=n;i++){
                if(a[i]<0) v.push_back(a[i]);
            }

            for(int i=1;i<=n;i++){
                if(a[i]==0) v.push_back(a[i]);
            }
        }

        int sum=0;
        bool fl=0;
        for(int i=1;i<=n;i++){
            sum+=v[i];
            if(sum==0){
                fl=1;
            }
        }

        if(fl){
            puts("NO");
            for(int i=1;i<=n;i++)
            cout<<v[i]<<' ';
            cout<<endl;
        } else {
            puts("YES");
            for(int i=1;i<=n;i++)
            cout<<v[i]<<' ';
            cout<<endl;
        }
    }
}