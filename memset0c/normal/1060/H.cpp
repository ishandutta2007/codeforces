#include<bits/stdc++.h>
const int X=1,Y=2,ANS=3,ZERO=4,CONSTMUL=5;
int cnt=5,d,p;
std::vector<int> f,v(5001,1);
inline int fpow(int a,int b){
  int s=1;
  for(;b;b>>=1,a=(long long)a*a%p)
    if(b&1)s=(long long)s*a%p;
  return s;
}
// inline void pow(int a,int b){v[b]=fpow(v[a],d);}
// inline void inc(int a,int b,int c){v[c]=(v[a]+v[b])%p;}
inline void pow(int a,int b){printf("^ %d %d\n",a,b);}
inline void inc(int a,int b,int c){printf("+ %d %d %d\n",a,b,c);}
void clear(int S){ // S=0
  pow(ZERO,S);
}
void constmul(int A,int b,int S){ // S+=A^b
  bool fl=false;
  while(b){
    if(b&1){
      if(fl){
        inc(S,CONSTMUL,S);
      }else{
        inc(S,A,S);
      }
    }
    b>>=1;
    if(fl){
      inc(CONSTMUL,CONSTMUL,CONSTMUL);
    }else{
      fl=true;
      inc(A,A,CONSTMUL);
    }
  }
}
void getzero(){ // ZERO=0
  constmul(++cnt,p-1,ZERO);
}
void opposite(int A,int S){ // S+=-A
  constmul(A,p-1,S);
}
void square(int A,int S){ // A=A^d, S=A^2
  clear(S);
  // printf("%d\n",v[A]);
  std::vector<int> pos(d+1);
  pos[0]=A;
  for(int i=1;i<pos.size();i++){
    pos[i]=++cnt;
    inc(pos[i-1],pos[i],pos[i]);
  }
  for(int i=0;i<pos.size();i++){
    pow(pos[i],pos[i]);
  }
  for(int i=0;i<pos.size();i++){
    if(f[i])constmul(pos[i],f[i],S);
    // printf("%d %d | S=%d\n",fpow(v[pos[i]],d),f[i],v[S]);
  }
}
void solve(){
  auto C=std::vector<std::vector<int>>(d+1,std::vector<int>(d+1,0));
  for(int i=0;i<=d;i++){
    C[i][0]=1;
    for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
  }
  auto P=std::vector<std::vector<int>>(d+1,std::vector<int>(d+1,0));
  for(int i=0;i<=d;i++){
    P[i][0]=1;
    for(int j=1;j<=d;j++)P[i][j]=(long long)P[i][j-1]*i%p;
  }
  auto A=std::vector<std::vector<int>>(d+1,std::vector<int>(d+2,0));
  for(int i=0;i<=d;i++)
    for(int j=0;j<=d;j++){
      A[j][i]=(long long)C[d][j]*P[i][d-j]%p;
    }
  // for(int i=0;i<=d;i++)
  // 	for(int j=0;j<=d;j++)
  // 		printf("%d%c",A[i][j]," \n"[j==d]);
  // putchar('\n');
  A[2][d+1]=1,f.resize(d+1);
  for(int i=0,j,k;i<=d;i++){
    for(j=i;j<=d;j++)if(A[j][i])break;
    if(i!=j)std::swap(A[i],A[j]);
    for(j=d+1;j>=i;j--)A[i][j]=(long long)A[i][j]*fpow(A[i][i],p-2)%p;
    for(j=i+1;j<=d;j++)for(k=d+1;k>=i;k--)A[j][k]=(A[j][k]+p-(long long)A[j][i]*A[i][k]%p)%p;
  }
  for(int i=d,j;i>=0;i--){
    f[i]=A[i][d+1];
    for(j=i-1;j>=0;j--)A[j][d+1]=(A[j][d+1]+p-(long long)A[j][i]*f[i]%p)%p,A[j][i]=0;
  }
  // for(int i=0;i<=d;i++)printf("%d%c",f[i]," \n"[i==d]);
}
int main(){
  // v[1]=3,v[2]=4,d=3,p=11;
  scanf("%d%d",&d,&p);
  solve();
  getzero();
  int Z=++cnt,X2=++cnt,Y2=++cnt,Z2=++cnt,S=++cnt;
  clear(S);
  // printf(">> X=%d Y=%d Z=%d\n",v[X],v[Y],v[Z]);
  inc(X,Y,Z);
  square(X,X2),opposite(X2,S);
  square(Y,Y2),opposite(Y2,S);
  square(Z,Z2),inc(Z2,S,S);
  // printf(">> X=%d Y=%d Z=%d\n",v[X2],v[Y2],v[Z2]);
  clear(ANS);
  constmul(S,(p+1)>>1,ANS);
  printf("f %d\n",ANS);
  // printf(">> %d\n",v[ANS]);
}