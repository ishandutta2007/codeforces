#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 1000000000000000LL

int main(){
  int i,j,k,l,m,n;
  ll cnv[300][300];
  ll res=0, tmp, g;
  char a[110000], b[110000], c[110000];
  char tmp1[10], tmp2[10];
  int len;

  rep(i,300) rep(j,300) cnv[i][j]=INF;
  rep(i,300) cnv[i][i]=0;

  scanf("%s%s%d",a,b,&n);
  rep(i,n){
    scanf("%s%s%d",tmp1,tmp2,&k);
    if(cnv[tmp1[0]][tmp2[0]] > k) cnv[tmp1[0]][tmp2[0]] = k;
  }

  REP(k,'a','z'+1) REP(i,'a','z'+1) REP(j,'a','z'+1) if(cnv[i][j]>cnv[i][k]+cnv[k][j]) cnv[i][j]=cnv[i][k]+cnv[k][j];

  for(i=0;;i++) if(a[i]<' ') break; len=i;
  for(i=0;;i++) if(b[i]<' ') break;
  if(i!=len){puts("-1"); return 0;}

  rep(k,len){
    tmp = INF;
    REP(i,'a','z'+1){
      g = cnv[a[k]][i] + cnv[b[k]][i];
      if(g < tmp) tmp = g, j=i;
    }
    if(tmp==INF) break;
    res += tmp; c[k] = j;
  }

  if(k!=len) puts("-1");
  else{
    c[len]='\0';
    printf("%I64lld\n%s\n",res,c);
  }

  return 0;
}