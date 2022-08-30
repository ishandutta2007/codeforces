#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}

int ps,p[1000000];
int app[1000000];

int edge[120][120], mn[120][120], mx[120][120], es[120];
int a[10000],b[10000],gcd[10000],lcm[10000];
int res[120], dame, per[120], copy[120];

int go(int now){
  int i,k,nx,res;

  rep(i,es[now]){
    if(mn[now][i]==per[now]){
      k=mx[now][i];
    } else if(mx[now][i]==per[now]) {
      k=mn[now][i];
    } else {
      return 0;
    }

    nx = edge[now][i];
    if(per[nx]>=0 && per[nx]!=k) return 0;
    if(per[nx]==-1){
      per[nx] = k;
      res = go(nx);
      if(!res){ per[nx]=-1; return 0; }
    }
  }

  return 1;
}

int main(){
  int i,j,k,l,m,n;
  int st,ed,x,y;
  int pn;

  ps = getPrime(1000000,p);

  while(scanf("%d%d",&n,&m)==2){
    rep(i,m){
      scanf("%d%d%d%d",a+i,b+i,gcd+i,lcm+i);
      a[i]--; b[i]--;
    }

    rep(i,m) if(lcm[i]%gcd[i]) break;
    if(i<m){puts("NO"); continue;}

    rep(i,1000000) app[i]=0;
    rep(i,m){
      k=lcm[i];
      rep(j,ps){
        if(p[j]*p[j] > k) break;
        while(k%p[j]==0) k/=p[j], app[p[j]]=1;
      }
      if(k>1) app[k]=1;
    }

    dame=0; rep(i,n) res[i]=1;
    rep(pn,1000000) if(app[pn]){
      rep(i,n) es[i]=0;
      rep(k,m){
        st = a[k]; ed = b[k];
        x = y = 0;
        while(gcd[k]%pn==0) x++, gcd[k]/=pn;
        while(lcm[k]%pn==0) y++, lcm[k]/=pn;
        edge[st][es[st]]=ed;  edge[ed][es[ed]]=st;
        mn[st][es[st]]=x;  mn[ed][es[ed]]=x;
        mx[st][es[st]]=y;  mx[ed][es[ed]]=y;
        es[st]++; es[ed]++;
      }

      rep(i,n) per[i]=-1;
      rep(i,n) if(per[i]==-1){
        if(es[i]==0){ per[i]=0; continue; }
        rep(k,n) copy[k]=per[k];
        per[i] = mn[i][0];
        k=go(i); if(k) continue;
        rep(k,n) per[k]=copy[k];
        per[i] = mx[i][0];
        k=go(i); if(k) continue;
        break;
      }
      if(i<n){dame=1; break;}
      rep(i,n) rep(j,per[i]) res[i] *= pn;
    }

    if(dame){puts("NO"); continue;}
    puts("YES");
    rep(i,n){
      if(i) putchar(' ');
      printf("%d",res[i]);
    }
    puts("");
  }

  return 0;
}