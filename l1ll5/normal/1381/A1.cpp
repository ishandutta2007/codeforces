#include <bits/stdc++.h>
#define N 200005
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
char A[N],B[N];
int a[N],b[N];
vector<int> ans;

void fl(int x){


    for(int i=1;i<=x;i++) a[i]=a[i]^1;
    reverse(a+1,a+x+1);
}

int main()
{
    //freopen("Example1.in","r",stdin);
    t=read();
    while(t--){
        n=read();
        ans.clear();
        scanf("%s",A+1);
        scanf("%s",B+1);
        for(int i=1;i<=n;i++) a[i]=A[i]-'0';
        for(int i=1;i<=n;i++) b[i]=B[i]-'0';

        int rev=0;
        int L=1,R=n;
        int fr=1;

        for(int i=n;i>=1;i--){
            int cur,tr;
            if(rev==0) cur=R;
            else cur=L;

            tr=fr;
        //    fr=cur;
        //    cerr<<i<<' '<<tr<<' '<<L<<' '<<R<<' '<<cur<<' '<<rev<<endl;

            int x=(a[cur])^rev;
            int y=b[i];

            if(x!=y){
                if((a[tr]^rev)!=b[i]){
                    ans.push_back(i);
                }
                else{
                    ans.push_back(1);
                //    a[tr]^=1;
                //    a[tr]=b[i];
                    ans.push_back(i);
                }
                rev^=1;

                fr=cur;
            }
                if(rev==0)R--;
                else L++;

        }

        for(int i=1;i<=n;i++) a[i]=A[i]-'0';
        for(int i=1;i<=n;i++) b[i]=B[i]-'0';

        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        //    fl(ans[i]);
        }
       puts("");
        /*cerr<<"+++++"<<endl;
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<endl;
        for(int i=1;i<=n;i++) cout<<b[i]<<' ';
        cout<<endl;*/
        //for(int i=1;i<=n;i++)
    }
}