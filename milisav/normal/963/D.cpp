#include<bits/stdc++.h>
using namespace std;
struct node {
    int lnk[27];
    vector<int> lf;
    int suf;
    int ex;
    pair<int,int> par;
};
char s[500000];
vector<char> m[500000];
int sz[500000];
vector<int> p[500000];
int k[500000];
int n;
int l;
char t[500000];
node a[2000000];
int get(int u);
int ext(int u);
int go(int u,int c) {
    if(u==0) return a[u].lnk[c];
    else {
        if(a[u].lnk[c]==-1) a[u].lnk[c]=go(get(u),c);
        return a[u].lnk[c];
    }
}
int get(int u) {
    if(u==0) return 0;
    else {
        if(a[u].suf==-1) {
            if(a[u].par.first==0) a[u].suf=0;
            else a[u].suf=go(get(a[u].par.first),a[u].par.second);
        }
        return a[u].suf;
    }
}
int ext(int u) {
    if(u==0) return 0;
    else {
        if(a[u].ex==-1) {
            if(a[get(u)].lf.size()>0) a[u].ex=get(u);
            else a[u].ex=ext(get(u));
        }
        return a[u].ex;
    }
}
int fid=1;
void celar() {
    for(int u=0;u<2000000;u++) {
        for(int j='a';j<='z';j++) a[u].lnk[j-'a']=-1;
        a[u].suf=-1;
        a[u].ex=-1;
        a[u].par={-1,-1};
    }
}
void add(int i) {
    int u=0;
    for(int j=0;j<m[i].size();j++) {
        if(a[u].lnk[m[i][j]-'a']==-1) {
            a[u].lnk[m[i][j]-'a']=fid;
            a[fid].par={u,m[i][j]-'a'};
            u=fid++;
        }
        else u=a[u].lnk[m[i][j]-'a'];
    }
    a[u].lf.push_back(i);
}
void recalc() {
    for(int j='a';j<='z';j++) {
        if(a[0].lnk[j-'a']==-1) a[0].lnk[j-'a']=0;
    }
    a[0].suf=0;
    a[0].ex=0;
    a[0].par={0,0};
}
void traverse() {
    int u=0,i=0;
    while(i<l) {
        u=go(u,s[i]-'a');
        int ct=u;
        while(ct!=0) {
            for(int j=0;j<a[ct].lf.size();j++) p[a[ct].lf[j]].push_back(i-sz[a[ct].lf[j]]+1);
            ct=ext(ct);
        }
        i++;
    }
}
vector<int> fd[500000];
int main() {
    celar();
    scanf("%s",s);
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %s",&k[i],t);
        int l=strlen(t);
        for(int j=0;j<l;j++) m[i].push_back(t[j]);
        sz[i]=l;
        add(i);
    }
    l=strlen(s);
    recalc();
    traverse();
    int ans=-1;
    for(int i=0;i<n;i++) {
        ans=-1;
        for(int j=0;j+k[i]-1<p[i].size();j++) {
            if(ans==-1 || p[i][j+k[i]-1]-p[i][j]+sz[i]<ans) ans=p[i][j+k[i]-1]-p[i][j]+sz[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}