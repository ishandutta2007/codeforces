#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 300
int n;
char z[MAX][MAX],wyn[MAX];
int d[MAX][MAX];
void nie(){
  puts("Impossible");
  exit(0);
}

const int m = 'z' - 'a' + 1;
void cmp(char *a, char* b){
  int i = 0;while(a[i] == b[i])i++;
  if(b[i] == 0)nie();
  if(a[i] != 0){
    //a[i] < b[i]
    d[a[i]-'a'][b[i]-'a'] = 1;
  }
}
bool cz[MAX];
main(){
  make(n);
  R(i,n)scanf("%s",z[i]);
  R(i,n-1)cmp(z[i],z[i+1]);
  R(_,m){
    R(i,m){
      if(cz[i] == 0){
        R(j,m){
          if(cz[j] == 0 && d[j][i])
            goto niet;
        }
        cz[i] = 1;
        wyn[_]=i+'a';
        goto end;
      }
      niet:;
    }
    nie();
    end:;
  }
  printf("%s\n",wyn);
}