#include <cstdio>

int n,x,y,c;

long long brd(int k, int x){
    if(k-x+1<=0)return 0;
    return ((long long)(k-x+1))*(k-x+1);
}

long long esq(int k, int x, int y){
    long long q=((long long)k)-x-y+1;
    if(q<=0)return 0;
    return (q*(q+1))/2;
}

long long f(int k){
    long long r=1+2*((long long)k)*(k+1);
    r-=brd(k,x);
    r-=brd(k,n-x+1);
    r-=brd(k,y);
    r-=brd(k,n-y+1);
    r+=esq(k,x,y);
    r+=esq(k,x,n-y+1);
    r+=esq(k,n-x+1,y);
    r+=esq(k,n-x+1,n-y+1);
    return r;
}

int main(){
    scanf("%d %d %d %d",&n,&x,&y,&c);
    int s=0,e=2*n+4,m;
    while(s+1<e){
        m=(s+e)/2;
        if(f(m-1)>=c){
            e=m;
        }
        else {
            s=m;
        }
    }
    printf("%d\n",s);
    return 0;
}