# include <iostream>
# include <cstdio>
# include <cstring>
# include <set>

using namespace std;
# define Mod 100000007

struct _hash{int a,b,c;}temp;
set<_hash> Q;
bool operator <(const _hash&t, const _hash&x)
{
    return t.a<x.a || t.a==x.a &&
        t.b<x.b || t.b==x.b &&
        t.c<x.c;
}
int n,limit;
char a[2000],c[27];
int s[2000];
namespace Hash{
    long long A[2000],X[2000];    //29
    long long B[2000],Y[2000];    //31
    long long C[2000],Z[2000];    //37
    void init()
    {
        A[0]=B[0]=C[0]=0;
        X[0]=Y[0]=Z[0]=1;
        for(int i=1;i<=n;i++)
        {
            A[i]=(A[i-1]*29+a[i])%Mod;
            B[i]=(B[i-1]*31+a[i])%Mod;
            C[i]=(C[i-1]*37+a[i])%Mod;
            X[i]=X[i-1]*29%Mod;
            Y[i]=Y[i-1]*31%Mod;
            Z[i]=Z[i-1]*37%Mod;
        }
    }
    _hash get(int l,int r)
    {
        _hash ret;
        ret.a=(A[r]-A[l-1]*X[r-l+1]%Mod+Mod)%Mod;
        ret.b=(B[r]-B[l-1]*Y[r-l+1]%Mod+Mod)%Mod;
        ret.c=(C[r]-C[l-1]*Z[r-l+1]%Mod+Mod)%Mod;
        return ret;
    }
}

int main()
{
//      freopen("input.txt","r",stdin);
    scanf("%s",a+1);    n=strlen(a+1);
    cin>>c;             scanf("%d",&limit);

    for(int i=1;i<=n;i++)a[i]-='a'-1;
    for(int i=0;i<26;i++)c[i]-='0';
    Hash::init();
    
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+(1-c[a[i]-1]);
//    for(int i=1;i<=n;i++)
//        cout<<(int)a[i];

    int Ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(s[j]-s[i-1]<=limit)
            {
                temp=Hash::get(i,j);
                if(Q.find(temp)==Q.end())
                {
                    Ans++;
//                    cout << i << ' ' << j << endl;
//                    cout << temp.a << ' '<<temp.b << ' ' << temp.c << endl;
                    Q.insert(set<_hash>::value_type(temp));
                }
            }
            else break;
    cout << Ans << endl;
//    while(1);
    return 0;
}