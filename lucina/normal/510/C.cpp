#include<bits/stdc++.h>
using namespace std;
int n,pa[110];
char s[110][500];
vector<int> a[50];
bool vis[110],u[110],ch;
stack<int> d;
void dfs(int nod){
    vis[nod]=true;
    u[nod]=true;
    for(auto i:a[nod]){
        if(!vis[i])
        dfs(i);
        else if(u[i]){
        printf("Impossible");
        exit(0);
        }
    }
    u[nod]=false;
    d.push(nod);
    return ;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s[0]);
    for(int i=1;i<n;i++){
        scanf("%s",s[i]);
         ch=true;
        for(int j=0;s[i][j]!='\0'&&s[i-1][j]!='\0';j++){
            if(s[i][j]!=s[i-1][j]){
                a[s[i-1][j]-'a'+1].push_back(s[i][j]-'a'+1);
                //printf("%d pb %d\n",s[i-1][j]-'a'+1,s[i][j]-'a'+1);
                ch=false;
                break;
            }
        }
        if(ch){
            if(strlen(s[i-1])>strlen(s[i])){
                printf("Impossible");
                return 0;
            }
        }
    }
    ch=true;
    for(int i=1;i<=26;i++){
        if(!vis[i])
        dfs(i);
    }
    if(ch){
        while(!d.empty()){
            printf("%c",d.top()+'a'-1);
            d.pop();
        }
    }
    else
        printf("Impossible");

}