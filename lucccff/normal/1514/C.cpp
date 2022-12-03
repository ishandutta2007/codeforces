#include <bits/stdc++.h>
using namespace std;

const int MAXN=100010;
int prime[MAXN+1],primen[10000],p[200];
int b[MAXN];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}


long long extend_gcd(long long a,long long b,long long &x,long long
&y){
    if(a == 0 && b == 0)return -1;
    if(b == 0 ){
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int m[20],a[20];// m,  a,X % m = a
bool solve(int &m0,int &a0,int m,int a){
    long long y,x;
    int g = extend_gcd(m0,m,x,y);
    if( abs(a - a0)%g )return false;
    x *= (a - a0)/g;
    x %= m/g;
    a0 = (x*m0 + a0);
    m0 *= m/g;
    a0 %= m0;
    if( a0 < 0 )a0 += m0;
    return true;
}
bool MLES(int &m0 ,int &a0,int n)// X = a0 + m0 * k
{
    bool flag = true;
    m0 = 1;
    a0 = 0;
    for(int i = 0;i < n;i++)
    if( !solve(m0,a0,m[i],a[i]) )
    {
        flag = false;
        break;
    }
    return flag;
}

int main(){
    int i,j,k,l,m1,n,t,r,s;
    cin>>n;
    k=n;
    getPrime();
    memset(primen,0,sizeof(primen));
    memset(p,0,sizeof(p));
    m1=0;
    for(i=1;i<=prime[0];i++) {
        if (k%prime[i]==0) p[m1++]=i;
        while(k%prime[i]==0) {
            k=k/prime[i];
            primen[i]++;
        }
    }
    int f=0;
    for(i=0;i<m1;i++) {
        if (p[i]!=1) {
            f=1;
            break;
        }
    }

    if ((n==2)||(n==4)) {
        cout<<1<<endl<<1;
        return 0;
    }
    memset(b,0,sizeof(b));
    k=n;
    for(i=0;i<m1;i++) {
        k=k/prime[p[i]]*(prime[p[i]]-1);
        for(j=prime[p[i]];j<=n;j+=prime[p[i]]) b[j]=1;
    }
    if (p[0]>1) {
        if (m1>=2){
            f=0;
        }
        else {
            f=1;
        }
    }
    else if (p[0]==1) {
        if (primen[1]>1) {
            f=0;
        }
        else {
            if (m1>2) {
                f=0;
            }
            else {
                f=1;
            }
        }
    }
    cout<<k-f<<endl;

    k=1;
    for(i=1;i<n-1;i++) {
        if (b[i]==0) {
            cout<<i<<' ';
            k=(k*i)%n;
        }
    }
    if (f==0) {
        cout<<n-1<<' ';
        k=(k*i)%n;
    }
    return 0;
}