#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int get_len(char a[]){
  int i;
  for(i=0;;i++) if(a[i]<' ') break;
  return i;
}

int is_same(char a[],char b[],int len){
  int i;
  rep(i,len) if(a[i]!=b[i]) return 0;
  return 1;
}

int n;
char in[111110]; int len;
char dic[12][122]; int dic_len[12];

int res1, res2;

int main(){
  int i,j,k,l,m;
  int st, ed;

  while(scanf("%s%d",in,&n)==2){
    res1 = res2 = 0;
    rep(i,n) scanf("%s",dic[i]);

    len = get_len(in);
    rep(i,n) dic_len[i] = get_len(dic[i]);

    st = 0;
    rep(ed,len){
      rep(i,n){
        if(ed-st+1 < dic_len[i]) continue;
        if(!is_same(dic[i],in+ed-dic_len[i]+1,dic_len[i])) continue;
        st = ed-dic_len[i]+2;
      }

      if(ed-st+1 > res1){
        res1 = ed-st+1;
        res2 = st;
      }
    }

    printf("%d %d\n",res1,res2);
  }

  return 0;
}