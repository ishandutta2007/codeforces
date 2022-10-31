#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 2100
#define MAXC 128
int array[4][MAXN*3+10],b[MAXN*3+10],*rk,*sa,*nsa,*nrk,n,n1,n2,height[MAXN*3+10],p[MAXN*3+10],ans,bg[MAXN*3+10];
char s[MAXN*3+10];
int a[MAXN*3+10][2];
void cal_sa(char *a){
    memset(b,0,300*sizeof(int));
    rk=array[0],nrk=array[1],sa=array[2],nsa=array[3];
    rk[n]=nrk[n]=-1;
    int i,k;
    for(i=0;i<n;i++)
        b[a[i]]++;
    for(i=1;i<=MAXC;i++)
        b[i]+=b[i-1];
    for(i=0;i<n;i++)
        sa[--b[a[i]]]=i;
    for(rk[sa[0]]=0,i=1;i<n;i++){
        rk[sa[i]]=rk[sa[i-1]];
        if(a[sa[i]]!=a[sa[i-1]])
            rk[sa[i]]++;
    }
    for(k=1;rk[sa[n-1]]<n-1;k<<=1){
        for(i=0;i<n;i++)
            b[rk[sa[i]]]=i;
        for(i=n-1;i>=0;i--)
            if(sa[i]>=k)
                nsa[b[rk[sa[i]-k]]--]=sa[i]-k;
        for(i=n-k;i<n;i++)
            nsa[b[rk[i]]--]=i;
        for(nrk[nsa[0]]=0,i=1;i<n;i++){
            nrk[nsa[i]]=nrk[nsa[i-1]];
            if(rk[nsa[i]]!=rk[nsa[i-1]]||rk[nsa[i]+k]!=rk[nsa[i-1]+k])
                nrk[nsa[i]]++;
        }
        swap(sa,nsa);
        swap(rk,nrk);
    }
}
void read(){
    scanf("%s",s);
    n1=strlen(s);
    n2=n1*2;
    int i;
    for(i=0;i<n1;i++)
        s[n2-i]=s[i];
    s[n1++]='$';
    n2++;
    s[n2++]='#';
    scanf("%s",s+n2);
    n=strlen(s+n2)+n2;
}
void cal_height(){
    int i,k=0,j;
    for(i=0;i<n;i++){
        if(!rk[i]){
            height[rk[i]]=0;
            continue;
        }
        if(k)
            k--;
        for(j=sa[rk[i]-1];s[i+k]==s[j+k];k++);
        height[rk[i]]=k;
    }
}
void solve(){
    int i,t=0,b;
    for(i=0;i<n;i++)
        if(sa[i]<n2){
            t=0x7fffffff;
            b=sa[i];
        }
        else{
            t=min(height[i],t);
            bg[sa[i]]=b;
            p[sa[i]]=t;
        }
    t=0x7fffffff;
    for(i=n-1;i;i--){
        if(sa[i-1]<n2){
            t=0x7fffffff;
            b=sa[i-1];
        }
        else{
            t=min(height[i],t);
            if(t>p[sa[i-1]])
                p[sa[i-1]]=t,bg[sa[i-1]]=b;
        }
    }
    for(i=n2;i<n;)
        if(!p[i]){
            ans=-1;
            break;
        }
        else{
            ans++;
            if(bg[i]>=n1)
                a[ans][1]=n2-bg[i]-1-p[i]+1,a[ans][0]=n2-bg[i]-1;
            else
                a[ans][0]=bg[i]+1,a[ans][1]=bg[i]+p[i];
            i+=p[i];
        }
}
int main()
{
    read();
    cal_sa(s);
    cal_height();
    solve();
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
        printf("%d %d\n",a[i][0],a[i][1]);
}