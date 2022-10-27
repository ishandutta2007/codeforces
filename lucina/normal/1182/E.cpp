#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,Lucina=4;
int mod=1e9+7;
int add(int a, int b) {
  a+=b;return a>=mod?a-mod:a;
}
int sub(int a, int b) {
  a -= b;return a<0?a+mod:a;
}
int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}
int power(int a,long long b) {
  int res = 1;
  while (b>0) {
    if (b&1) {
      res = mul(res,a);
    }
    a = mul(a,a);
    b >>= 1;
  }
  return res;
}
struct matrix{
    int m[5][5];
    matrix (){
        memset(m,0,sizeof(m));
    }
    void print(){
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            printf("%d%c",m[i][j],j==Lucina?'\n':' ');
    }
    int* operator [] (int r) {
        return m[r];
    }

    matrix I(){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
            tmp[i][i]=1;
        return tmp;
    }
    friend matrix operator +( matrix x, matrix y){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            tmp[i][j]=add(x[i][j],y[i][j]);
        return tmp;
    }
    friend matrix operator *( matrix x, matrix y){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
        for(int j=0;j<=Lucina;j++){
            for(int r=0;r<=Lucina;r++){
                tmp[i][j]=add(tmp[i][j],mul(x[i][r],y[r][j]));
            }
        }
        return tmp;
    }
    matrix power(matrix x,long long b){
        matrix tmp=I();
        while(b>0){
            if(b&1){
            tmp=(tmp*x);
            }
        x=(x*x);
        b>>=1;
        }
        return tmp;
    }

};
map<int,int> vals;
const int g=(int) sqrt (mod + .0) + 1;

int solve(int a, int b) {
    for (int q = 0;q<=g;++q) {
        int cur = mul(power(5, q), b);
        if (vals.count(cur)) {
            int ans = sub(mul(vals[cur],g), q);
            return ans;
        }
    }
    return -1;
}



int main(){
    for (int p = g; p >= 1; --p)
        vals[power(5,mul(p, g))] = p;
    int q[4];
    long long n;
    //pp();
    scanf("%lld",&n);
    for(int i=1;i<=3;i++){
        scanf("%d",&q[i]);
        q[i]=solve(5,q[i]);
    }
    int x;
    scanf("%d",&x);

   /* for(int i=1;i<=3;i++)
        printf("%d ",q[i]);*/
    x=solve(5,x);
    //printf("\n");
    matrix a;
    a[0][0]=q[3];a[1][0]=q[2];a[2][0]=q[1];a[4][0]=1;
    a[3][0]=2;
    matrix l;
    l[0][0]=1;l[0][1]=1;l[0][2]=1;l[0][3]=x;
    for(int i=1;i<=2;i++)
        l[i][i-1]=1;
    l[3][3]=1;l[4][4]=1;l[3][4]=2;
    //l.print();
    //cout<<"KUYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n"
    //a.print();
    mod--;
    //a.print()
   // l.print();
    l=l.power(l,n-3);
    //l.print();
    //a.print();
    //I hate matrix expoooooo
    a=l*a;
    mod++;
    printf("%d",power(5,a[0][0]));

}