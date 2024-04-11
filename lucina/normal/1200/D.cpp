#include<stdio.h>
const int maxn=2003;
int n,ans,k,pos,cur;
void upd(int &x,int y){
    if(x<y)x=y;return;
}
struct pa{
    short l,r;
}pr[2003],pc[2003];
char s[2001][2001];
short r[2003],c[2003],x[2003],stp[2003];
bool z;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int L,R;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            x[j]=x[j-1]+(s[i][j]=='W');
         L=-1,R=-1;
        for(int j=1;j<=n;j++){
            z=(x[j-1]==j-1);
            pos=j+k;if(pos>n+1)pos=n+1;
            z&=((x[n]-x[pos-1])==(n+1-pos));
            if(z&&(L==-1))L=j;
            if(z)R=j;
        }
        r[i]=r[i-1]+(x[n]==n);
        pr[i]={L,R};
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++)
            x[i]=x[i-1]+(s[i][j]=='W');
        L=-1,R=-1;
        for(int i=1;i<=n;i++){
            z=(x[i-1]==i-1);
            pos=i+k;if(pos>n+1)pos=n+1;
        z&=((x[n]-x[pos-1])==(n+1-pos));
        if(z&&(L==-1))L=i;
        if(z)R=i;
        }
        c[j]=c[j-1]+(x[n]==n);
        pc[j]={L,R};
    }
    int now,S,pos1;
    for(int j=1;j<=k;j++){
            if(pr[j].l==-1)continue;
            stp[pr[j].l]++;
            stp[pr[j].r+1]--;
        }
    for(int i=1;i<=n-k+1;i++){
        now=0,S=0;
        for(int j=1;j<=k;j++){
            if(i>=pc[j].l&&i<=pc[j].r)
            now++;
        }
        pos1=i+k-1;
        for(int j=1;j<=n-k+1;j++){
            cur=r[i-1]+c[j-1];
            cur+=(r[n]-r[pos1]);
            cur+=(c[n]-c[j+k-1]);
            S+=stp[j];
            upd(ans,cur+S+now);
            if(i>=pc[j].l&&i<=pc[j].r){
                now--;
            }
            if(i>=pc[j+k].l&&i<=pc[j+k].r){
                now++;
            }
        }
        if(pr[i].l!=-1){
            stp[pr[i].l]--;
            stp[pr[i].r+1]++;
        }
        if(pr[i+k].l!=-1){
            stp[pr[i+k].l]++;
            stp[pr[i+k].r+1]--;
        }
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/