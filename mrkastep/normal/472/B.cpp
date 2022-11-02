#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#define For(i,n) for(i=0;i<(n);i++)

int max(int x,int y){
    return x>y?x:y;
}

int min(int x,int y){
    return x<y?x:y;
}

bool letter(char x){
    return (x>='a'&&x<='z')?true:false;
}

std::string get_str(){
    char x,c[55];
    std::string l;
    while(!letter(x=getchar()));
    l+=x;
    while(letter(x=getchar())){
        l+=x;
    }
    return l;
}


void solve(int n){
    int i,f[2222],p,k,mx=0,mn=10000,s[2222],ans=0,t;
    scanf("%d",&k);
    For(i,2222) f[i]=s[i]=0;
    For(i,n){
        scanf("%d",&p);
        f[p]++;
        mx=mx<p?p:mx;
        mn=mn>p?p:mn;
    }
    s[mx]=f[mx];
    for(i=mx-1;i>mn-1;i--){
        s[i]=s[i+1]+f[i];
    }
    t=s[mn]/k;
    if(s[mn]%k!=0) t++;
    t*=2;
    t--;
    t*=mn-1;
    ans+=t;
    for(i=mn+1;i<=mx;i++){
        t=s[i]/k;
        if(s[i]%k!=0) t++;
        t=t*2-1;
        ans+=t;
    }
    ans+=mx-1;
    printf("%d",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}