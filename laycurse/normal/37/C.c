#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int node, left[20000], right[20000], used[20000];
char now[2000];
char res[1200][1200];

int dfs(int k, int depth,int target){
  int i,j;

  if(used[k]==2) return 0;
  if(used[k]==0 && target==depth){
    used[k]=2;
    return 1;
  }
  if(target==depth) return 0;

  if(used[k]==0){
    used[k]=1;
    left[k]=node++;
    right[k]=node++;
    used[left[k]] = used[right[k]] = 0;
  }

  now[depth] = '0';
  if(dfs(left[k],depth+1,target)) return 1;
  now[depth] = '1';
  if(dfs(right[k],depth+1,target)) return 1;

  return 0;
}

int main(){
  int i,j,k,l,m,n;

  scanf("%d",&n);
  node = 1; used[0] = 0;
  rep(i,n){
    scanf("%d",&k);
    if(dfs(0,0,k)==0) break;
    rep(m,k) res[i][m] = now[m]; res[i][k]='\0';
  }
  if(i<n) puts("NO");
  else {
    puts("YES");
    rep(i,n) puts(res[i]);
  }

  return 0;
}