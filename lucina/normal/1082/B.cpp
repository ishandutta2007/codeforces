#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,l,r,mi,f,ans,id;
char s[maxn];
int pos[maxn],len[maxn];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    s[n+1]='S';
    f=0,id=0,ans=0;
    for(int i=1;i<=n+1;i++){
       if(f==0&&s[i]=='G'){
            f++;
            ans=max(ans,f);
            continue;
            }
        if(s[i]=='G'){
            f++;
            ans=max(ans,f);
            continue;
        }
        if(s[i]=='S'||s[i]=='\0'){
            ans=max(ans,f);
            id++,pos[id]=i,len[id]=f;
            f=0;
        }
    }
    int a=0,b=0,c=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='G')
            a++;
        else b++;
    }
    for(int i=1;i<=id;i++){
            c=0;
        if(s[pos[i]+1]=='G'){
            if(len[i]+len[i+1]<a){
                c+=len[i+1]+len[i]+1;
                }
            if(len[i]+len[i+1]==a)
                c+=len[i+1]+len[i];
                ans=max(ans,c);
        }
        if(s[pos[i]+1]=='S'||s[pos[i]+1]=='\0'){
            c=0;
            if(len[i]!=a){
                c=len[i]+1;
                ans=max(ans,c);
                }
        }
    }
    printf("%d\n",ans);

}