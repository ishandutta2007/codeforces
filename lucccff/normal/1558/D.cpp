#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

typedef struct node
{
    int f;
    struct node *next,*head;
}node;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long i,j,k,l,m,n,t,x,y,z,g;
    long long a[200010],b[200010],inv[400010],jie[400010],ijie[400010];
    node *p,*q,*c[2010],*head,*s,*d[200010];
    c[0]=head=p=(node *)malloc(sizeof(node));
    for(j=1;j<=200000;j++) {
        q=(node *)malloc(sizeof(node));
        q->f=0;
        q->head=p;
        p->next=q;
        p=q;
        if (j%401==0) c[j/401]=p;
    }
    inv[1]=1;
    jie[0]=jie[1]=j=1;
    ijie[0]=ijie[1]=k=1;
    for(i=2;i<=400000;i++) {
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        j=j*i%MOD;
        jie[i]=j;
        k=k*inv[i]%MOD;
        ijie[i]=k;
    }
    cin>>t;
    g=0;
    for(i=0;i<t;i++) {
        cin>>n>>m;
        l=1;
        /*for(j=0;j<m;j++) {
            cin>>k>>x;
            while(l<k) {
                a[l]=l;
                l++;
            }
            a[l++]=x;
        }
        while(l<=n) {
            a[l]=l;
            l++;
        }*/
        k=401;
        //c[0]=head=p=(node *)malloc(sizeof(node));
        //p->f=0;
        for(j=1;j<=m;j++) {
            cin>>x>>y;
            q=(node *)malloc(sizeof(node));
            /*if (a[j]==j) {
                q->f=0;
                q->head=p;
                p->next=q;
                p=q;
            }
            else {*/
            q->f=1;
            d[g++]=q;
            l=(y-1)/k;
            s=c[l];
            for(x=0;x<(y-1)%k;x++) {
                s=s->next;
            }
            s->f=0;
            q->head=s;
            q->next=s->next;
            s->next=q;
            q->next->head=q;
            for(x=l+1;x<=2e5/k;x++) {
                c[x]=c[x]->head;
            }
        }
        z=0;
        p=head;
        for(j=g-m;j<g;j++) {
            z+=d[j]->f;
            d[j]->f=0;
        }
        cout<<(ijie[n]*ijie[n-z-1]%MOD)*jie[n+n-z-1]%MOD<<endl;
    }
    return 0;
}