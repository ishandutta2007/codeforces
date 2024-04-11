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

std::string s[2][100100];
int ans[100100];

void solve(int n){
    int i,p,t;
    std::string s1,s2;
    bool g=true;
    For(i,n){
        s1=get_str();
        s2=get_str();
        if(s1>s2){
            s[0][i]=s2;
            s[1][i]=s1;
        }
        else{
            s[0][i]=s1;
            s[1][i]=s2;
        }
    }
    scanf("%d",&p);
    p--;
    ans[p]=0;
    t=p;
    For(i,n-1){
        scanf("%d",&p);
        p--;
        if(s[0][p]>s[ans[t]][t]){
            ans[p]=0;
        }
        else{
            if(s[1][p]>s[ans[t]][t]){
                ans[p]=1;
            }
            else{
                g=false;
            }
        }
        t=p;
    }
    if(g) printf("YES");
    else printf("NO");
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