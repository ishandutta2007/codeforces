#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[105],n,k,s,t,Lucina;
inline int add(int a, int b) {
  a+=b;return a>=mod?a-mod:a;
}

inline int sub(int a, int b) {
  a -= b;return a<0?a+mod:a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

inline int power(int a,int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
struct matrix{
    int m[102][102];
    matrix (){
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            m[i][j]=0;
    }
    matrix I(){
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
            tmp.m[i][i]=1;
        return tmp;
    }
    matrix operator *(const matrix x)const{
        matrix tmp;
        for(int i=0;i<=Lucina;i++)
        for(int j=0;j<=Lucina;j++){
            for(int r=0;r<=Lucina;r++){
                tmp.m[i][j]=add(tmp.m[i][j],mul(m[i][r],x.m[r][j]));
            }
        }
        return tmp;
    }
    matrix power(matrix x,int b){
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
    void print(){
        for(int i=0;i<=Lucina;i++)
            for(int j=0;j<=Lucina;j++)
            printf("%d%c",m[i][j],j==Lucina?'\n':' ');
    }
};

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        Lucina+=(a[i]==0);
        }
    if(Lucina==0||Lucina==n)
    return printf("1"),0;
    for(int i=1;i<=Lucina;i++){
        t+=(a[i]==0);
    }
    matrix x;
    x.m[t][0]=1;
    int d=(n*(n-1))/2;
    d=power(d,mod-2);
    matrix l;
   int peace=((Lucina*(Lucina-1))+((n-Lucina)*(n-Lucina-1)))/2;
    for(int i=0;i<=Lucina;i++){
            l.m[i][i]+=peace;
            l.m[i][i]+=((n-Lucina*2+i*2)*(Lucina-i));
            if(i-1>=0)
            l.m[i][i-1]+=((Lucina-i+1)*(Lucina-i+1));
            if(i+1<=Lucina)
            l.m[i][i+1]+=((i+1)*(n-Lucina-Lucina+i+1));
            l.m[i][i-1]=mul(l.m[i][i-1],d);
            l.m[i][i+1]=mul(l.m[i][i+1],d);
            l.m[i][i]=mul(l.m[i][i],d);
        }
    //l.print();
    l=l.power(l,k);
    matrix ans=l*x;
    //ans.print();
    printf("%d\n",ans.m[Lucina][0]);

}