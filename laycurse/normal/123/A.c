#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int main(){
  int i,j,k,l,m,n;
  int ind[1001];
  int num[1001], sz;
  char in[1020];
  int cnt[26];
  int dame = 0;

  while(scanf("%s",in)==1){
    n = strlen(in);
    rep(i,26) cnt[i] = 0;
    rep(i,n) cnt[in[i]-'a']++;
    rep(i,n) in[i] = 0;
    
    unionInit(ind,n+1);

    for(i=2;i<=n;i++){
      for(j=2*i;j<=n;j+=i) unionConnect(ind, i, j);
    }

    k = 0;
    REP(i,1,n+1) if(unionGet(ind,2)==unionGet(ind,i)) k++;

    rep(i,26) if(cnt[i] >= k){
      REP(j,1,n+1) if(unionGet(ind,2)==unionGet(ind,j)){
        cnt[i]--;
        in[j-1] = 'a'+i;
      }
      break;
    }
    if(i==26){puts("NO"); continue;}

    rep(i,n) if(!in[i]){
      rep(j,26) if(cnt[j]) break;
      cnt[j]--; in[i] = j+'a';
    }
    puts("YES");
    puts(in);
  }

  return 0;
}