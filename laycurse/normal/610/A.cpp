#include<bits/stdc++.h>
using namespace std;

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

int main(){
  int N;
  reader(&N);
  if(N%2) writerLn(0);
  else    writerLn((N/2-1)/2);

  return 0;
}