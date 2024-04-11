#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int l,r;
int m;
void solve(){
    for(int i=l;i<=r;i++){

        int ls=m/i;
        int rs=m/i+1;

        int dis=1e18;

        for(int j=-2;j<=2;j++){
            int n=m/i+j;
            if(n<=0) continue ;

            int mn=n*i;

            if(abs(m-mn)<=r-l){
                int c_b=mn-m;
                for(int c=l;c<=r;c++)
                {
                    int tb=c-c_b;
                    if(tb>=l && tb<=r){
                        cout<<i<<' '<<tb<<' '<<c<<endl;
                    //    assert(n*i+tb-c == m);
                    //    cerr<<"a"<<n*i+tb-c<<' '<<m<<' '<<i<<' '<<tb<<' '<<c<<endl;
                        return ;
                    }
                }
            }
        }


    }
}
main()
{
    cin>>T;
    while(T--){
        cin>>l>>r>>m;
        solve();

    }
}