#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y;
int is_ok(int a,int b){
  if(a<0||b<0||a>=x||b>=y) return 0;
  return 1;
}

int mp[200][200];
char res[200][200];
int chk[200];

void nul(int i,int j,int from,int to,int fg){
  if(!is_ok(i,j)) return;
  if(fg==-1){
    if(res[i][j]) chk[res[i][j]-'a']=1;
  }
  if(mp[i][j]!=from) return;
  mp[i][j]=to;
  if(fg>=0){
    res[i][j]=fg+'a';
  }

  nul(i-1,j  ,from,to,fg);
  nul(i+1,j  ,from,to,fg);
  nul(i  ,j-1,from,to,fg);
  nul(i  ,j+1,from,to,fg);
}

int main(){
  int i,j,k,l,m,n;
  int a,b,c,dame;

  scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
  rep(i,x) rep(j,y) mp[i][j]=-1;
  k=0; dame=0;

  if(x%2==1){
    rep(j,y) if(mp[0][j]==-1 && is_ok(0,j+1) && mp[0][j+1]==-1){
      a--;
      mp[0][j]=mp[0][j+1]=k++;
    }
  }
  if(y%2==1){
    rep(i,x) if(mp[i][0]==-1 && is_ok(i+1,0) && mp[i][0]==-1){
      b--;
      mp[i][0]=mp[i+1][0]=k++;
    }
  }

  rep(i,x) rep(j,y) if(mp[i][j]==-1){
    if(is_ok(i+1,j+1) && mp[i][j]==-1 && c>0){
      c--;
      mp[i][j]=mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=k++;
      continue;
    }
    if(is_ok(i+1,j+1) && mp[i][j]==-1 && a>=2){
      a-=2;
      mp[i][j]=mp[i][j+1]=k++;
      mp[i+1][j]=mp[i+1][j+1]=k++;
      continue;
    }
    if(is_ok(i+1,j+1) && mp[i][j]==-1 && b>=2){
      b-=2;
      mp[i][j]=mp[i+1][j]=k++;
      mp[i][j+1]=mp[i+1][j+1]=k++;
      continue;
    }
    dame=1;
  }

  if(a<0 || b<0 || c<0) dame=1;

  if(dame) puts("IMPOSSIBLE");
  else {
    rep(i,x) rep(j,y) res[i][j]=0;
    rep(i,x) rep(j,y) if(!res[i][j]){
      rep(k,26) chk[k]=0;
      nul(i,j,mp[i][j],-5,-1);
      rep(k,26) if(!chk[k]) break;
      nul(i,j,-5,-1,k);
    }
    rep(i,x) res[i][y]='\0';
    rep(i,x) puts(res[i]);
  }


  return 0;
}