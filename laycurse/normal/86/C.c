#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int is_same(char a[], char b[], int len){
  int i;
  rep(i,len) if(a[i]!=b[i]) return 0;
  return 1;
}

#define M 1000000009

int n, lim;
char in[12][12]; int len[12];

int dp[1011][12][12][12];
char *digit = "ACGT";

int edge1[12][12][12][4];
int edge2[12][12][12][4];
int edge3[12][12][12][4];

void edge_generator(void){
  int i,j,k;
  int word, word_len, ok_len;
  int next_word, next_word_len, next_ok_len;
  int fin, match, ok_chk;
  char now[120]; int now_len;
  int mx;

  rep(word,n) rep(word_len,len[word]) rep(ok_len,word_len+1) rep(k,4){
    fin = 0;

    rep(i,word_len) now[i] = in[word][i];
    now[word_len] = digit[k];
    now_len = word_len+1;

    match = 0;
    rep(i,n) if(now_len >= len[i]) if(ok_len + len[i] >= now_len){
      if(is_same(in[i], now+now_len-len[i], len[i])) match = 1;
    }

    next_word = 0; next_word_len = 0; next_ok_len = 0;
    if(match) fin = 1;
    
    rep(i,n) REP(j,1,len[i]){
      if(next_word_len >= j) continue;
      if(is_same(in[i],now+now_len-j,j)==0) continue;

      if(match) ok_chk = j;
      else      ok_chk = ok_len - (now_len - j);

      if(ok_chk < 0) continue;

      fin = 1;
      next_word = i;
      next_word_len = j;
      next_ok_len = ok_chk;
    }

    if(fin==0){edge1[word][word_len][ok_len][k] = -1; continue;}
    edge1[word][word_len][ok_len][k] = next_word;
    edge2[word][word_len][ok_len][k] = next_word_len;
    edge3[word][word_len][ok_len][k] = next_ok_len;
  }
}

int solve(int depth, int word, int word_len, int ok_len){
  int i,j,k;
  int next_word, next_word_len, next_ok_len;
  int res = 0;

  if(dp[depth][word][word_len][ok_len] >= 0) return dp[depth][word][word_len][ok_len];
  if(depth==lim){
    if(word_len==ok_len) res++;
    return dp[depth][word][word_len][ok_len] = res;
  }

  rep(k,4){
    if(edge1[word][word_len][ok_len][k] < 0) continue;
    next_word     = edge1[word][word_len][ok_len][k];
    next_word_len = edge2[word][word_len][ok_len][k];
    next_ok_len   = edge3[word][word_len][ok_len][k];

    res += solve(depth+1, next_word, next_word_len, next_ok_len);
    res %= M;
  }

  return dp[depth][word][word_len][ok_len] = res;
}

int main(){
  int i,j,k,l,m,res;

  while(scanf("%d%d",&lim,&n)==2){
    rep(i,n) scanf("%s",in[i]);
    rep(i,n){
      for(j=0;;j++) if(in[i][j]<' ') break;
      len[i] = j;
    }

    rep(i,1011) rep(j,12) rep(k,12) rep(l,12) dp[i][j][k][l] = -1;
    edge_generator();

    res = solve(0,0,0,0);
    printf("%d\n",res);
  }

  return 0;
}