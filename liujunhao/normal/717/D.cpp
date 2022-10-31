#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
#define MAXX 100
int n,x;
double p[MAXX+10];
struct Matrix{
    double a[128][128];
    inline Matrix(){
        memset(a,0,sizeof a);
    }
    inline Matrix(int){
        memset(a,0,sizeof a);
        for(int i=0;i<128;i++)
            a[i][i]=1;
    }
    inline Matrix operator*(const Matrix &b){
        Matrix c;
        int i,j,k;
        for(i=0;i<128;i++)
            for(j=0;j<128;j++)
				for(k=0;k<128;k++)
					c.a[i][k]=(c.a[i][k]+a[i][j]*b.a[j][k]);
        return c;
    }
    inline Matrix& operator*=(const Matrix&b){
        return *this=*this*b;
    }
}A;
Matrix quick_pow(Matrix a,long long b){
    Matrix ret(1);
    while(b){
        if(b&1)
            ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
void read(){
	Read(n),Read(x);
	int i,j;
	for(i=0;i<=x;i++)
		scanf("%lf",&p[i]);
	for(i=0;i<128;i++)
		for(j=0;j<=x;j++)
			A.a[i^j][i]=p[j];
	A=quick_pow(A,n);
}
int main()
{
	read();
	printf("%.10lf",(double)(1-A.a[0][0]));
}