#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int in[200000];
ll q[3][200000]; int q_st[3], q_size[3], w[3];
int go, ed;

int main(){
  int i,j,l,m,n;
  int k[3];
  int t[3];
  ll res, tm, next;

  while(scanf("%d%d%d",k,k+1,k+2)==3){
    scanf("%d%d%d",t,t+1,t+2);
    scanf("%d",&n);
    rep(i,n) scanf("%d",in+i);

    rep(i,3) q_st[i] = q_size[i] = w[i] = 0;

    res = 0;
    tm = 0; go = ed = 0;
    while(ed < n){
      next = 1000000000000000000LL;

      if(go < n && in[go] < next) next = in[go];
      rep(i,3) if(q_size[i]) if(q[i][q_st[i]] < next) next = q[i][q_st[i]];
      rep(i,3) if(q_size[i]<k[i] && w[i] && next > tm) next = tm;

      tm = next;
      if(go < n && in[go] == tm) w[0]++, go++;
      rep(i,3) if(q_size[i]) if(q[i][q_st[i]] == tm){
        q_st[i]++; q_size[i]--;
        if(i==0 || i==1) w[i+1]++;
        else {
          if(tm - in[ed] > res) res = tm - in[ed];
          ed++;
        }
      }
      rep(i,3) if(q_size[i]<k[i] && w[i]){
        w[i]--;
        q[i][q_st[i]+q_size[i]++] = tm + t[i];
      }
    }

    printf("%I64d\n",res);
  }

  return 0;
}