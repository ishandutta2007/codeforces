#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}*/
char v[30];
int mat[10][10];
bool eatc (int a, int b, int x, int y)
{
    if(a==x)
        return true;
    if(b==y)
        return true;
    if(a+b==x+y)
        return true;
    if(a-b==x-y)
        return true;
    return false;
}
int dx[]={0,0,-1,1,1,1,-1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
/// "Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", or "Up-Right"
int getdir ()
{
    int n=strlen(v);
    if(n==5)
        return 0;
    if(n==4 && v[0]=='L')
        return 1;
    if(n==2)
        return 2;
    if(n==4)
        return 3;
    if(n==5+5)
        return 4;
    if(n==5+4)
        return 5;
    if(n==3+4)
        return 6;
    if(n==3+5)
        return 7;
}
int aux[10][10];
void moves (int dir, int a, int b)
{
    int i,j;
    for(i=1;i<=8;++i)
        for(j=1;j<=8;++j)
            aux[i+dx[dir]][j+dy[dir]]=mat[i][j];
    for(i=1;i<=8;++i)
        for(j=1;j<=8;++j)
        {
            mat[i][j]=aux[i][j];
            if(eatc(i,j,a,b))
                mat[i][j]=0;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,k,m,n;
    cin>>t;
    while(t--)
    {
        for(i=1;i<=8;++i)
            for(j=1;j<=8;++j)
                mat[i][j]=1;
        mat[1][1]=0;
        cout<<"1 1\n";
        cout.flush();
        cin>>v;
        if(strlen(v)==4 && v[2]=='n')
            continue;
        int dir=getdir();
        int a=1,b=1;
        moves(dir,a,b);
        while(a<8)
        {
            int pz=0;
            for(j=1;j<=8;++j)
                if(mat[a+1][j])
                    pz=j;
            if(pz==0)
            {
                cout<<a+1<<' '<<b<<'\n';
                cout.flush();
                ++a;
                cin>>v;
                if(strlen(v)==4 && v[2]=='n')
                    break;
                dir=getdir();
                moves(dir,a,b);
            }
            else
            {
                cout<<a<<' '<<pz<<'\n';
                cout.flush();
                b=pz;
                cin>>v;
                if(strlen(v)==4 && v[2]=='n')
                    break;
                dir=getdir();
                moves(dir,a,b);
            }
        }
    }
    return 0;
}